#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=1e5+10;
int h[maxn];
int n;

void solve()
{
    for(int i=0;i<n;i++) cin>>h[i];
    stack<int> left,right;
    vector<int> suf(n),pre(n);
    for(int i=0;i<n;i++)
    {
        while(!left.empty() && h[i]<=h[left.top()])
        {
            left.pop();
        }
        pre[i]=left.empty()?-1:left.top();
        left.push(i);
    }

    for(int i=n-1;i>=0;i--)
    {
        while(!right.empty() && h[i]<=h[right.top()])
        {
            right.pop();
        }
        suf[i]=right.empty()?n:right.top();
        right.push(i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,h[i]*1LL*(suf[i]-pre[i]-1));
    }
    cout<<ans<<"\n";
}

signed main()
{
    while(cin>>n) solve();
}