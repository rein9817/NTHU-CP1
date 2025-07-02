#include<bits/stdc++.h>
using namespace std;
const int maxn=2505;
const long long minn=-1e17;
int n,m,u,v;
long long w,c,d[maxn],cnt[maxn];
bool flag,dd[maxn],mark[maxn];
typedef pair<long long,int>ii;
vector<ii>g[maxn];
vector<int>rg[maxn];
queue<int>q;

void rdfs(int u){
    mark[u]=true;
    for(int v:rg[u])if(mark[v]==false)rdfs(v);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>c;
        g[u].push_back({c,v});
        rg[v].push_back(u);
    }
    for(int i=1;i<=n;i++)d[i]=minn;
    d[1]=0;
    dd[1]=true;
    q.push(1);
    rdfs(n);
    while(!q.empty()){
        u=q.front();
        q.pop();
        dd[u]=false;
        for(ii i:g[u]){
            v=i.second;
            w=i.first;
            if(d[v]<d[u]+w){
                d[v]=d[u]+w;
                if(dd[v]==false){
                    cnt[v]++;
                    if(cnt[v]<=n){
                        q.push(v);
                        dd[v]=true;
                    }
                    else if(mark[v]){
                        flag=true;
                        break;
                    }
                }
            }
        }
    }
    if(flag){
        cout<<-1;
        return 0;
    }
    cout<<d[n];
}