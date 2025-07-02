#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];

int main()
{
    int n,k;
    cin>>n>>k;
    map<int,int> cnt;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    vector<pair<int,int>> query;
    while(q--)
    {
        int type,pos;
        cin>>type>>pos;
        query.push_back({pos,type});
    }
    sort(query.begin(),query.end());
    for(auto x:query)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    int left=0;
    int right=0;
    sort(a,a+n);
    while(left<n && right<q)
    {
        
    }
}