#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
#define int long long 

signed main()
{
    int n;
    cin>>n;
    vector<array<int,3>> temp(n+1);
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        temp[i]={a,b,c};
    }
    sort(temp.begin()+1,temp.end(),[&](array<int,3> a,array<int,3> b)
    {
        return a[1]<b[1];
    });
    vector<int> days(n+1);
    for(int i=1;i<=n;i++)
    {
        days[i]=temp[i][1];
    }

    for(int i=1;i<=n;i++)
    {
        int j=lower_bound(days.begin()+1,days.end(),temp[i][0])-days.begin()-1;
        dp[i]=max(dp[j]+temp[i][2],dp[i-1]);
    }
    cout<<dp[n]<<"\n";
}