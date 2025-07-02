#include <bits/stdc++.h>
using namespace std;
#define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long 
#define f first
#define s second
#define ALL(x) begin(x),end(x)
const int maxn=200010;

using pii=pair<int,int>;
int parent[maxn];
int check[maxn];

int find(int x)
{
    return x==parent[x]?x:parent[x]=find(parent[x]);
}

void merge(int a,int b)
{
    a=find(a);b=find(b);
    if(a==b) return ;
    parent[a]=b;
}

void solve()
{
    rein
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        merge(a,b);
    }
    for(int i=1;i<=n;i++)
    {
        check[find(i)]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(check[i]) ans++;
    }
    cout<<ans<<"\n";
}

signed main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}