#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
int table[maxn][maxn];
bool visited[maxn][maxn];

int n, m;
int ans = 0;

int dirx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int diry[8] = {1, 0, -1, 0, 1, -1, 1, -1};
bool check(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m; 
}
void dfs(int x, int y) 
{
    if(x==n-1 && y==m-1)
    {
        ans++;
        return ;
    }
    // cout<<x<<' '<<y<<endl;
    visited[x][y]=1;
    for(int dir=0;dir<8;dir++)
    {
        int nx=x+dirx[dir];
        int ny=y+diry[dir];
        if(check(nx,ny) && !visited[nx][ny])
        {   
            dfs(nx,ny);
        }
    }
    // visited[x][y]=0;
}

void solve() 
{
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>table[i][j];
            if(!table[i][j])
            {
                cout<<0<<endl;
                return ;
            }
        }
    }
    dfs(0, 0);
    cout<<ans<<"\n";
}

int main() {
    solve();
}
