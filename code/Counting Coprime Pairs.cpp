#include <bits/stdc++.h>
using namespace std;
#define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long 
#define f first
#define s second
#define ALL(x) begin(x),end(x)
const int maxn=2000100;


using pii=pair<int,int>;
int a[maxn];
int mobius[maxn];
int lpf[maxn];
int cnt[maxn];



void pre()
{
    for(int i=2;i<maxn;i++)
    {
        if(!lpf[i])
        {
            for(int j=i;j<maxn;j+=i)
            {
                if(!lpf[j]) lpf[j]=i;
            }
        }
    }
}

void Mobius()
{
    for(int i=1;i<maxn;i++)
    {
        if(i==1) mobius[i]=1;
        else {
            if(lpf[i/lpf[i]]==lpf[i]) mobius[i]=0;
            else mobius[i]=-1*mobius[i/lpf[i]];
        }
    }
}
void solve()
{
    rein
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    pre();
    Mobius();
    int ans=0;
    for(int i=1;i<maxn;i++)
    {
        if(mobius[i]==0)
        {
            continue;
        }
        int d=0;
        for(int j=i;j<maxn;j+=i)
        {
            d+=cnt[j];
        }
        ans+=(d*(d-1))/2*mobius[i];
    }
    cout<<ans<<"\n";
}
signed main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}