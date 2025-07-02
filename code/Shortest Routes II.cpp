#include <bits/stdc++.h>
using namespace std;
#define int long long 
int table[505][505];
int n,m,q;
void floydwarshall()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                table[i][j]=min(table[i][j],table[i][k]+table[k][j]);
            }
        }
    }
}
signed main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            table[i][j]=1e18;
        }
        table[i][i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        table[a][b]=min(table[a][b],c);
        table[b][a]=table[a][b];
    }
    floydwarshall();
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(table[a][b]==1e18) cout<<-1<<'\n';
        else cout<<table[a][b]<<"\n";
    }
}