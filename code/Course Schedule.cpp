#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+19;
vector<int> edge[maxn];
int indeg[maxn];
int main()
{
    #define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m ;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty())
    {
        auto head=q.front();
        q.pop();
        ans.push_back(head);
        for(int u:edge[head])
        {
            indeg[u]--;
            if(!indeg[u])
            {
                q.push(u);
            }
        }
    }
    if((int)ans.size()!=n)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else {
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
    }
}