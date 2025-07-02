#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define all(s) s.begin(),s.end()
#define pll pair<long long,long long>
const int INF=1e18+7;
const int MOD=1e9+7;
const int sz=2e5+1;
using namespace std;
vector<int>g[sz];
int d[2][sz];

void dfs(int node,int par,int ind)
{
    for(int i:g[node])
    {
        if(i==par)
            continue;
        d[ind][i]=d[ind][node]+1;
        dfs(i,node,ind);
    }
}

signed main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,1,0);
    int mx=0,ind=1;
    for(int i=1;i<=n;i++)
    {
        if(d[0][i]>mx)
        {
            mx=d[0][i];
            ind=i;
        }
        d[0][i]=0;
    }
    dfs(ind,ind,0);
    mx=0;
    for(int i=1;i<=n;i++)
    {
        if(d[0][i]>mx)
        {
            mx=d[0][i];
            ind=i;
        }
    }
    dfs(ind,ind,1);
    for(int i=1;i<=n;i++) cout<<max(d[0][i],d[1][i])<<" ";
}