#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> ans;
int a[100];
bitset<100> visited;

void dfs(int idx,vector<int> &temp)
{
    if(idx>=n) return ;
    if(temp.size()==m)
    {
        ans.push_back(temp);
        return ;
    }
    for(int i=idx;i<n;i++)
    {
        if(visited[i]) continue;
        visited[i]=true;
        temp.push_back(a[i]);
        dfs(i,temp);
        temp.pop_back();
        visited[i]=false;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> v;
    dfs(0,v);
    for(auto x:ans)
    {
        for(int y:x)
        {
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}