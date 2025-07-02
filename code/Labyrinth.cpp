#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define f first
#define s second
#define mp make_pair
int n, m;
const int maxn=1010;
string table[maxn];
bool vis[maxn][maxn];
int previousStep[maxn][maxn];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
string s= "URDL";
pii source, target;


int main() 
{
	cin >> n >> m;
	queue<pii> q;
	for (int i = 0; i < n; i++) {
        cin>>table[i];
		for (int j = 0; j < m; j++) {
			if (table[i][j] == 'A') source = mp(i, j);
            else if (table[i][j] == 'B') target = mp(i, j);
		}
	}
    auto check=[&](pii temp)->bool
    {
        if (temp.f < 0 || temp.f >= n || temp.s < 0 || temp.s >= m) return false;
		if (table[temp.f][temp.s] == '#') return false;
		if (vis[temp.f][temp.s]) return false;
        return true;
    };
	q.push(source);
	vis[source.f][source.s] = true;
	while (!q.empty()) 
    {
		auto u = q.front();q.pop();
		for (int i = 0; i < 4; i++) 
        {
			auto v = mp(u.f + dx[i], u.s + dy[i]);
			if(!check(v)) continue;
			vis[v.f][v.s] = true;
			previousStep[v.f][v.s] = i;
			q.push(v);
		}
	}

	if (vis[target.f][target.s]) {
		cout << "YES" << endl;
		vector<int> steps;
		while (source!=target) 
        {
			int p = previousStep[target.f][target.s];
			steps.push_back(p);
			target= mp(target.f-dx[p],target.s-dy[p]);
		}
        cout << steps.size() << endl;
		reverse(steps.begin(), steps.end());
		for (char c : steps) { cout<<s[c]; }
		cout << endl;
	}
    else cout << "NO" << endl;
}