#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e6+10;
const int mod=1e9+7;
int fac[maxn];
int inv[maxn];
int fastpow(int base,int k,int p)
{
    if(k==0) return 1;
    int ans=1;
    while(k)
    {
        if(k&1) ans=(ans*base)%p;
        base=(base*base)%p;
        k>>=1;
    }
    return ans;
}
void fact()
{
    fac[0]=1;
    for(int i=1;i<=maxn;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
}
void inverse()
{
    inv[maxn]=fastpow(fac[maxn],mod-2,mod);
    for(int i=maxn;i>=1;i--)
    {
        inv[i-1]=(inv[i]*i)%mod;
    }
}

signed main()
{
    int t;
    cin>>t;
    fact();
    inverse();
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<(fac[a]%mod*inv[a-b]%mod*inv[b]%mod)%mod<<"\n";
    }   
}