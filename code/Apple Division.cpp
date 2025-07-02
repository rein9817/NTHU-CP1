#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    using ll=long long ;
    vector<int> a(n);
    ll sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    
    ll ans=LONG_LONG_MAX;
    for(int i=0;i<(1<<n);i++)
    {
        ll temp=0;
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1) temp+=a[j];
        }
        ans=min(ans,abs(temp-(sum-temp)));
    }
    cout<<ans<<"\n";
}