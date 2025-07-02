#include <bits/stdc++.h>
using namespace std;
#define int long long 

int fastpow(int base,int k,int mod)
{
    if(k==0) return 1;
    base%=mod;
    int ans=1;
    while(k)
    {
        if(k&1)
        {
            ans=(ans*base)%mod;
        }
        base=(base*base)%mod;
        k>>=1;
    }
    return ans;
}

signed main()
{
    int n;
    cin>>n;
    int mod=1e9+7;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<fastpow(a,fastpow(b,c,mod-1),mod)<<"\n";
    }
}