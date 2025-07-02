#include <bits/stdc++.h>
using namespace std;
const int maxn=3005;

int dp[maxn][maxn];

int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans;
    int len=dp[n][m];
    int i=n;
    int j=m;
    while(len)
    {
        if(s[i-1]==t[j-1])
        {
            ans+=s[i-1];
            len--;
            i--;
            j--;
        }
        else 
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
}