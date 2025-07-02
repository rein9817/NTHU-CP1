#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,q;
int a[200010 + 9];
int seg[200010 * 4 + 9];

void pull(int id)
{
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
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
    if (r < ql || qr < l) return LONG_LONG_MAX;
    if (ql <= l && r <= qr) return seg[id];
    int mid = (l + r) / 2;
    return min(
        query(id * 2, l, mid, ql, qr),
        query(id * 2 + 1, mid + 1, r, ql, qr)
    );
}


signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    build(1, 1, n);
    
    while ( q -- ) {
        int op; cin >> op;  
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            modify(1, 1, n, i, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
}