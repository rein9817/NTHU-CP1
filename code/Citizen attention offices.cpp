#include <bits/stdc++.h>
using namespace std;
int table[5][5];

using ll=long long;
ll ans=LONG_LONG_MAX;
int visited[5];
vector<int> res;

void dfs(int level,int cnt)
{
    if(cnt>=5)
    {
        ll sum=0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                int temp=INT_MAX;
                for(int k=0;k<5;k++)
                {
                    if(abs(visited[k]/5-i)+abs(visited[k]%5-j)<temp)
                    {
                        temp=abs(visited[k]/5-i)+abs(visited[k]%5-j);
                    }
                }
                sum+=temp*table[i][j];
            }
        }
        if(sum<ans)
        {
            ans=sum;
            res.clear();
            for(int i=0;i<5;i++)
            {
                res.push_back(visited[i]);
            }
        }
        return;
    }
    for(int i=level;i<25;i++) 
    {
        visited[cnt]=i;
        dfs(i+1,cnt+1);
    }
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(table,0,sizeof(table));
        int n;
        cin>>n;
        while(n--)
        {
            int r,c,a;
            cin>>r>>c>>a;
            table[r][c]=a;
        }
        ans=LONG_LONG_MAX;
        dfs(0,0);
        for(int i=0;i<5;i++)
        {
            cout<<res[i]<<(i!=4?" ":"\n");
        }
    }
}
