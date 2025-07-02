#include <bits/stdc++.h>
using namespace std;

string table[7];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int ans;
bool visited[7][7];

void dfs(int x,int y)
{   
    if(x==7 && y==7)
    {
        ans++;
        return ;
    }
    cout<<x<<" "<<y<<endl;
    if(table[x][y]=='?')
    {
        for(int dir=0;dir<4;dir++)
        {
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||nx>7||ny<0||ny>7||visited[nx][ny]) continue;
            visited[nx][ny]=true;
            dfs(nx,ny);
            visited[nx][ny]=false;
        }
    }
    else {
        char c=table[x][y];
        switch(c)
        {
            int nx,ny;
            case 'R':
                nx=x;ny=y+1;
                if(nx<0||nx>7||ny<0||ny>7||visited[nx][ny]) return;
                visited[nx][ny]=true;
                dfs(nx,ny);
                visited[nx][ny]=false;
                break;
            case 'L':
                nx=x-1;ny=y;
                if(nx<0||nx>7||ny<0||ny>7||visited[nx][ny]) return;
                visited[nx][ny]=true;
                dfs(nx,ny);
                visited[nx][ny]=false;
                break;
            case 'U':
                nx=x-1;ny=y;
                if(nx<0||nx>7||ny<0||ny>7||visited[nx][ny]) return;
                visited[nx][ny]=true;
                dfs(nx,ny);
                visited[nx][ny]=false;
                break;
            case 'D':
                nx=x+1;ny=y;
                if(nx<0||nx>7||ny<0||ny>7||visited[nx][ny]) return;
                visited[nx][ny]=true;
                dfs(nx,ny);
                visited[nx][ny]=false;
                break;
        }
    }
}
int main()
{
    for(int i=0;i<7;i++) cin>>table[i];
    ans=0;
    dfs(0,0);
    cout<<ans<<endl;   
}