#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int maxn=1e5+10;
vector<int> edge[maxn];
//0:white 1:black
int dp[maxn][2];

void dfs(int cur,int parent)
{
    dp[cur][0]=1;
    dp[cur][1]=1;
    for(int x:edge[cur])
    {
        if(x==parent) continue;
        dfs(x,cur);
        dp[cur][0]=dp[cur][0]*(dp[x][1]+dp[x][0])%mod;
    }

    for(int x:edge[cur])
    {
        if(x==parent) continue;
        dp[cur][1]=dp[cur][1]*dp[x][0]%mod;
    }
}

signed main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1])%mod<<"\n";
}