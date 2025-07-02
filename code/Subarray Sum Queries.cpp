#include <iostream>
#define int long long
 
using namespace std;
 
struct node
{
    int l, r, best; // qed
    int sum;
};
 
node tree[800005];
 
void update(int nd, int l, int r, int qp, int newv)
{
    if(qp < l || r < qp)
        return;
    if(qp == l && qp == r)
    {
        tree[nd].l=max(0LL, newv);
        tree[nd].r=max(0LL, newv);
        tree[nd].best=max(0LL, newv);
        tree[nd].sum=newv;
        return;
    }
    int mid=(l+r)/2;
    update(nd*2+1, l, mid, qp, newv);
    update(nd*2+2, mid+1, r, qp, newv);
    tree[nd].sum=tree[nd*2+1].sum+tree[nd*2+2].sum;
    tree[nd].l=max(tree[nd*2+1].l, tree[nd*2+1].sum+tree[nd*2+2].l);
    tree[nd].r=max(tree[nd*2+2].r, tree[nd*2+2].sum+tree[nd*2+1].r);
    tree[nd].best=max(max(tree[nd*2+1].best, tree[nd*2+2].best), tree[nd*2+1].r+tree[nd*2+2].l);
    tree[nd].best=max(tree[nd].best, tree[nd].l);
    tree[nd].best=max(tree[nd].best, tree[nd].r);
}
 
int32_t main()
{
    int n, m;
    cin>>n>>m;
    int k, v;
    for(int i=1; i<=n; i++)
    {
        cin>>v;
        update(0, 1, n, i, v);
    }
    while(m--)
    {
        cin>>k>>v;
        update(0, 1, n, k, v);
        cout<<tree[0].best<<'\n';
    }
}