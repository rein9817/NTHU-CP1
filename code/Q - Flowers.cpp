#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=2e5+10;
int a[maxn];
int h[maxn];
int bit[maxn];
int dp[maxn];

int ans;

int lowbit(int x)
{
    return x&-x;
}

void update(int pos,int val)
{
    for(int i=pos;i<=maxn;i+=lowbit(i))
    {
        bit[i]=max(bit[i],val);
    }
}

int query(int pos)
{
    int sum=0;
    while(pos>0)
    {
        sum=max(sum,bit[pos]);
        pos-=lowbit(pos);
    }
    return sum;
}

signed main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
       dp[i]=query(h[i])+a[i];
       ans=max(ans,dp[i]);
       update(h[i],dp[i]);
    }
    cout<<ans<<"\n";
}