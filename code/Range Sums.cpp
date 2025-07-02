#include <iostream>
#include <vector>
using namespace std;
int n, q;
vector<int> e[201000];
bool vis[201000];

void dfs(int u)
{
	vis[u] = 1;
	for(int v : e[u]) 
    {
        if (!vis[v])dfs(v);
    }
}

int main()
{
	cin >> n >> q;
	while (q--)
    {
		int l, r;
		cin >> l >> r;
		e[l - 1].push_back(r);
		e[r].push_back(l - 1);
	}
	dfs(0);
	if (vis[n]) cout << "Yes"; 
    else cout << "No";
}