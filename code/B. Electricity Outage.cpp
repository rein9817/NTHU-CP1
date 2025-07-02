#include <bits/stdc++.h>
using namespace std;

#define rein ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

signed main() 
{
    rein
    int n;
    cin>>n;
    set<pair<int, int>> s;
    for (int i=0;i<n;++i) 
    {
        int op,l,r,x;
        cin >> op;
        if (op==1) {
            cin >> l >> r;
            s.insert({l, r});
        } 
        else 
        {
            cin>>x;
            auto it=s.lower_bound({x,LONG_LONG_MAX});
            if (it!=s.begin() && (--it)->second>=x) cout<<0<<"\n";
            else cout<<1<<"\n";
        }
    }
}
