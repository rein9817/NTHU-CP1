#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second
#define ALL(x) begin(x),end(x)
const int maxn=200010;
vector<int> edge[maxn];
using pii=pair<int,int>;
int seg[4*maxn];
int a[maxn];
int n,q;

void pull(int id)
{
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    pull(id);
}

void modify(int id, int l, int r, int i, int x) {
    if (l == r) {
        seg[id] = x;
        return;
    }
    int mid = (l + r) / 2;
    if(i<=mid) modify(id * 2, l, mid, i, x);
    else modify(id * 2 + 1, mid + 1, r, i, x);
    pull(id);
}

int query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[id];
    int mid = (l + r) / 2;
    return max(
        query(id * 2, l, mid, ql, qr),
        query(id * 2 + 1, mid + 1, r, ql, qr)
    );
}

void queryupdate(int val, int l = 1, int r = n, int node = 1) {
	if (l == r) {
		seg[node] -= val;
		cout << l << ' ';
        return ;
	}
	int mid = (l + r) / 2;
	if (seg[node * 2] >= val) queryupdate(val, l, mid, node * 2);
	else queryupdate(val, mid + 1, r, node * 2 + 1);
    pull(node);
}

signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n);
    
    while ( q -- ) {
        int x;
        cin>>x;
        if(x>seg[1])
        {
            cout<<0<<" ";
            continue;
        }
        queryupdate(x);
    }
}