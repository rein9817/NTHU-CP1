#include <bits/stdc++.h>
#define int long long 
using namespace std;

typedef struct node{
    int sum;
    int id;
    int maximum;
    int cnt;
}node;
node cnt[3000];

bool cmp(node a,node b)
{
    return a.sum>b.sum||(a.sum==b.sum && a.maximum>b.maximum) || (a.sum==b.sum && a.maximum==b.maximum && a.cnt>b.cnt) ||(a.sum==b.sum && a.maximum==b.maximum && a.cnt==b.cnt && a.id>b.id);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>());
        for(int i=0;i<n;i++)
        {
            int r;
            cin>>r;
            int temp=0;
            int large=-1;
            for(int j=0;j<r;j++){
                int x;
                cin>>x;
                a[i].push_back(x);
                temp+=x;
                large=max(large,x);
            }
            cnt[i].cnt=r;
            cnt[i].sum=temp;
            cnt[i].id=i;
            cnt[i].maximum=large;
        }
        sort(cnt,cnt+n,cmp);
        for(int i=0;i<n;i++)
        {
            for(int x:a[cnt[i].id]) cout<<x<<' ';
            cout<<"\n";
        }
    }
}