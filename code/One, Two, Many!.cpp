#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<int> edge[maxn];
int visited[maxn];

void dfs(int cur,int color)
{
    visited[cur]=color;
    for(int x:edge[cur])
    {
        if(visited[x]==color)
        {
            cout<<"MANY\n";
            exit(0);
        }
        if(visited[x]==3-color) continue;
        dfs(x,3-color);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i,1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<visited[i]<<" ";
    }
    cout<<"\n";
}