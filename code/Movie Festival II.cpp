#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> temp(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        temp[i]={b,a};
    }
    sort(temp.begin(),temp.end());
    int ans=0;
    multiset<int> s;
    for(int i=0;i<k;i++) s.insert(0);
    for(auto x:temp)
    {
        auto it=s.upper_bound(x.second);
        if(it==s.begin()) continue;
        s.erase(--it);
        ans++;
        s.insert(x.first);
    }
    cout<<ans<<"\n";
}