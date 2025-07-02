#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) a.push_back(a[i]);
    deque<int> q;
    for(int i=0;i<k;i++) {
        while(!q.empty() && a[i]>=a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    vector<int> ans={a[q.front()]};
    for(int i=k;i<2*n;i++)
    {
        while(!q.empty() && a[i]>=a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        while(q.front()<=i-k)
        {
            q.pop_front();
        }
        ans.push_back(a[q.front()]);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
}   