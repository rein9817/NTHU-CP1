#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) for(int i=0;i<n;i++)
#define N 1000010
#define int long long 
using namespace std;

int a[N];
int prefix[N];
int t,l,r,ans,n,st;
int R[N],L[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>prefix[i+1];
            prefix[i+1]+=prefix[i];
        }
        st=0;
        for(int i=0;i<n+1;i++)
        {
            while(st&&prefix[a[st-1]]<=prefix[i]) 
            {
                R[a[--st]]=i;
            }
            a[st++]=i;
        }
        while(st--) 
        {
            R[a[st]]=n+1;
        }
        st=0;
        for(int i=0;i<n+1;i++)
        {
            while(st && prefix[a[st-1]] > prefix[i])
            {
                L[a[--st]]=i;
            }
            a[st++]=i;
        }
        while(st--)
        {
            L[a[st]]=n+1;
        }
        l=r=ans=0;
        while(l<n)
        {
            while(r<=n&&R[r]<L[l])
            {
                r=R[r];
            }
            ans=max(ans,r-l);
            l=r=r+1;
        }
        cout<<ans<<"\n";
    }   
}