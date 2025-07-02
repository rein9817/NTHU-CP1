#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    k--;
    vector<int> p(n);
    for(int &x:p)
    {
        int a,b,c;
        cin>>a>>b>>c;
        x=a+b+c;
    }
    vector<int> q=p;
    nth_element(q.begin(),q.begin()+k,q.end(),greater<int>());
    for(int x:p)
    {
        cout<<(x+300>=q[k]?"Yes\n":"No\n");
    }
}