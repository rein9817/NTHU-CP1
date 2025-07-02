#include <bits/stdc++.h>
using namespace std;

int stick[24],len;
bool flag;
bool visited[24];
int n;


void dfs(int cnt , int now_length , int pos)
{
    if(cnt==3)
    {
        flag=true;
        return;
    }
    if(now_length == len) dfs(cnt+1,0,0);
    if(now_length >= len||flag) return;
    for(int i=pos;i<n;i++)
    {
        if(!visited[i])
        {
            if(now_length + stick[i] <= len)
            {
                visited[i]=1;
                dfs(cnt, now_length + stick[i],i+1);
                visited[i]=0;
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>stick[i];
            sum += stick[i];
        }
        memset(visited,0,sizeof(visited));
        sort(stick,stick+n ,greater<int>());
        len =sum/4;
        flag= false;

        if(sum%4||stick[0]>len) cout<<"no\n";
        else
        {
            dfs(0,0,0);
            if(flag) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
}
