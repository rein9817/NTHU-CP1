#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=1e5+10;

int a[maxn];
int b[maxn];
int g[maxn];
int cur[maxn];
int n,k;
bool check(int mid)
{
    for(int i=0;i<n;i++) cur[i]=a[i]+mid*g[i];
    int cnt=0;
    int ans=0;
    sort(cur,cur+n);
    for(int i=0;i<n;i++)
    {
        if(cur[i]>b[cnt])
        {
            ans++;
            cnt++;
        }
    }
    return ans>=k;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i]>>g[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int left=-1;
        int right=1e8;
        sort(b,b+n);
        if(!check(1e8))
        {
            cout<<"-1\n";
            continue;
        }
        while(left+1<right)
        {
            int mid=left+(right-left)/2;
            if(check(mid))right=mid;
            else left=mid;
        }
        cout<<right<<"\n";
    }
}