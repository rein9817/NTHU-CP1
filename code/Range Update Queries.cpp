#include <bits/stdc++.h>
using namespace std;
#define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long 
#define f first
#define s second
#define ALL(x) begin(x),end(x)
const int maxn=200010;
vector<int> edge[maxn];
using pii=pair<int,int>;

int bit[maxn];
int n,q;
int lowbit(int x)
{
    return x&-x;
}

int query(int x)
{
    int ans=0;
    while(x)
    {
        ans+=bit[x];
        x-=lowbit(x);
    }
    return ans;
}
void update(int x,int d)
{
    while(x<=n)
    {
        bit[x]+=d;
        x+=lowbit(x);
    }
}
void solve()
{
    cin>>n>>q;
    int pre=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        update(i,x-pre);
        pre=x;
    }
    while(q--)
    {
        int t,x,y,z;
        cin>>t;
        if(t==1)
        {
            cin>>x>>y>>z;
            update(x,z);
            update(y+1,-z);
        }
        else {
            cin>>x;
            cout<<query(x)<<"\n";
        }
    }
}
signed main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}