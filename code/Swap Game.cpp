#include <bits/stdc++.h>
using namespace std;
 
string ans="123456789";
int dx[2]={1,0};
int dy[2]={0,1};
 
int main()
{
    string temp;
    char c;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>c;
            temp+=c;
        }
    }
    
    queue<pair<string,int>> q;
    q.push({temp,0});
    unordered_set<string> visited;
    visited.insert(temp);
    while(!q.empty())
    {
        auto [s,dist]=q.front();q.pop();
        if(s==ans)
        {
            cout<<dist<<"\n";
            return 0;
        }
        for(int i=0;i<8;i++)
        {
            int x=i/3;
            int y=i%3;
            for(int dir=0;dir<2;dir++)
            {
                int nx=x+dx[dir];
                int ny=y+dy[dir];
                if(nx<0||ny<0||nx>=3||ny>=3) continue;
                int origin=nx*3+ny;
                if(origin<0||origin>=9) continue;
                string temp=s;
                swap(temp[i],temp[origin]);
                if(visited.count(temp)) continue;
                visited.insert(temp);
                q.push({temp,dist+1});
            }
        }
    }
}
