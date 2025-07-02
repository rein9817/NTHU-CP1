#include <bits/stdc++.h>
using namespace std;
#define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long 
#define f first
#define s second
#define ALL(x) begin(x),end(x)
const int maxn=200010;

using pii=pair<int,int>;
vector<int> edge[maxn];
int Size[maxn];
int n;

int ans;

void dfs(int cur,int parent)
{
    int max_son_size=0;
    Size[cur]=1;
    for(int x:edge[cur])
    {   
        if(x==parent) continue;
        dfs(x,cur);
        Size[cur]+=Size[x];
        max_son_size=max(max_son_size,Size[x]);
    }
    max_son_size=max(max_son_size,n-Size[cur]);
    if(max_son_size<=n/2) 
    {
        cout<<cur<<"\n";
        exit(0);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,-1);
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