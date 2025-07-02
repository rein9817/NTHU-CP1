#include <bits/stdc++.h>
#define int long long 

using namespace std;

int bfs(int jug1Capacity, int jug2Capacity, int targetCapacity) 
{
    queue<array<int,3>> q;
    q.push({0,0,0});
    map<pair<int,int>,int> cnt;
    cnt[{0,0}]=1;
    while(!q.empty())
    {
        auto [x,y,dist]=q.front();q.pop();
        if(x>jug1Capacity||y>jug2Capacity) continue;
        if(x==targetCapacity||y==targetCapacity) return dist;
        if(cnt[{jug1Capacity,y}]!=1) {
            q.push({jug1Capacity,y,dist+1});
            cnt[{jug1Capacity,y}]=1;
        }
        if(cnt[{x,jug2Capacity}]!=1) {
            q.push({x,jug2Capacity,dist+1});
            cnt[{x,jug2Capacity}]=1;
        }
        if(cnt[{0,y}]!=1) {
             q.push({0,y,dist+1});
            cnt[{0,y}]=1;
        }
        if(cnt[{x,0}]!=1) {
            q.push({x,0,dist+1});
            cnt[{x,0}]=1;
        }
        int a=x-min(jug2Capacity-y,x);
        int b=y+min(jug2Capacity-y,x);
        if(cnt[{a,b}]!=1) {
            q.push({a,b,dist+1});
            cnt[{a,b}]=1;
        }
        a=x+min(jug1Capacity-x,y);
        b=y-min(jug1Capacity-x,y);
        if(cnt[{a,b}]!=1) 
        {
            q.push({a,b,dist+1});
            cnt[{a,b}]=1;
        }
    }
    return -1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>q;
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp=bfs(a[i],a[j],q);
            if(temp==-1) continue;
            ans=min(ans,temp);
        }
    }
    if(ans!=INT_MAX) cout<<ans<<"\n";
    else cout<<-1<<"\n";
}