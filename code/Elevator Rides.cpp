#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[25];
int dp[1<<22];
int last[1<<22];

signed main()
{
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    dp[0]=1;
    last[0]=0;
    for(int i=1;i<(1<<n);i++)
    {
        dp[i]=INT_MAX;
        last[i]=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                int s=i & ~(1<<j);
                if(last[s]+a[j]<=x)
                {
                    if(dp[s]<dp[i]||(dp[s]==dp[i] && last[s]+a[j]< last[i]))
                    {
                        last[i]=last[s]+a[j];
                        dp[i]=dp[s];
                    }
                }
                else 
                {
                    if(dp[s]+1<dp[i]||(dp[s]+1==dp[i] && a[j] <last[i]))
                    {
                        last[i]=a[j];
                        dp[i]=dp[s]+1;
                    }   
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
}