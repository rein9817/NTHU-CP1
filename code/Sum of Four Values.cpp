#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn];

int main()
{
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<int,pair<int,int>> cnt;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            int temp=x-a[i]-a[j];
            if(cnt.find(temp)!=cnt.end())
            {
                cout<<i+1<<' '<<j+1<<" "<<cnt[temp].first+1
                <<" "<<cnt[temp].second+1<<"\n";
                return 0;
            }
        }
        for(int j=i+1;j<n;j++)
        {
            cnt[a[i]+a[j]]={i,j};
        }
    }
    cout<<"IMPOSSIBLE\n";
}