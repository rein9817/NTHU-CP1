#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
vector<int> cnt(maxn+1);

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=maxn;i>0;i--)
    {
        int div=0;
        for(int j=i;j<maxn;j+=i) div+=cnt[j];
        if(div>=2)
        {
                cout<<i<<endl;
                break;
        }
    }
}