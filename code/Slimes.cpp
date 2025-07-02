#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[410];
int dp[510][510];
int prefix[500];

signed main()
{
    int n;
    cin>>n;
    prefix[0]=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
        dp[i][i]=0;
    }
    for(int len=2;len<=n;len++)
    {
        for(int l=1,r=len;r<=n;l++,r++)
        {
            int temp=LONG_LONG_MAX;
            for(int k=l;k<r;k++)
            {
                temp=min(temp,dp[l][k]+dp[k+1][r]);
            }

            dp[l][r]=temp+prefix[r]-prefix[l-1];
        }
    }
    cout<<dp[1][n]<<'\n';
}