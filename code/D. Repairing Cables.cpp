#include <bits/stdc++.h>
using namespace std;
#define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ALL(x) begin(x),end(x)
#define int long long 
const int maxn=1e5+10;
int a[maxn];
using pii=pair<int,int>;

int n, m;

int check(int mid) 
{
    int ans=0;
    for (int i=0; i<n; i++) 
    {
        ans=max(ans,a[i]+mid+1/mid);
    }
    return ans;
}

signed main() 
{
    rein
    cin >> n >> m;
    int temp=0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        temp=max(temp,a[i]);
    }
    int k=m-n;
    if(k==0)
    {
        cout<<temp<<"\n";
        return 0;
    }
    int left=1,right=k;
    int ans=LONG_LONG_MAX;
    while (left<=right) 
    {
        int mid=left+(right-left)>>1;
        if (check(mid)<ans) {
            // cout<<mid<<endl;
            ans=mid;
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    cout<<ans<<"\n";
}
