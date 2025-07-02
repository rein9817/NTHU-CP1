#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,m,s,t;
#define int long long 

int cal(int time)
{
    int used_time=m/c; //means current time 
    int current_m=m%c;
    int dist=used_time*b;
    int ans=0;
    int current_time=used_time;
    if(current_time<time)
    {
        int gap=time-current_time;
        for(int i=0;i<=gap;i++) //枚舉充氣時間去算能跑的最大距離
        {
            int current_dist=dist;
            current_time=used_time+i;
            current_m=(m%c)+d*i;
            int step=min(current_m/c,time-current_time); //充氣花的時間
            // current_m=current_m-step*c;
            current_dist+=step*b; //更新計算出的距離
            current_time+=step; //加進去充氣花的時間
            current_dist+=(time-current_time)*a;
            ans=max(ans,current_dist);
        }
    }
    else ans=b*time;
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c>>d>>m>>s>>t;
    int dist=cal(t);
    if(s>=dist) cout<<"No\n"<<dist<<"\n";
    else {
        cout<<"Yes\n";
        int left=0,right=t;
        while(right-left>1)
        {
            int mid=left+(right-left)/2;
            if(cal(mid)>s) right=mid;
            else left=mid;
        }
        cout<<right<<"\n";
    }
}