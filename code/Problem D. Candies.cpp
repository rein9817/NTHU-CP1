#include <bits/stdc++.h>
using namespace std;
#define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long 
#define f first
#define s second
#define ALL(x) begin(x),end(x)
const int maxn=200010;
vector<int> edge[maxn];
using pii=pair<int,int>;

pii exgcd(int a,int b)
{
    if(b==0) return {1,0};
    auto temp=exgcd(b,a%b);
    return {temp.second,temp.first-a/b*temp.second};
}

void solve()
{
    vector<pii> temp(3);
    int product=1;
    for(int i=0;i<3;i++)
    {
        cin>>temp[i].first>>temp[i].second;
        product*=temp[i].first;
    }
    int ans=0;
    for(int i=0;i<3;i++)
    {
        int tempa=product/temp[i].f;
        ans+=(1LL*temp[i].second*exgcd(tempa,temp[i].f).f*tempa);

    }
    cout<<(ans%product+product)%product<<"\n";
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}