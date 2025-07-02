#include<bits/stdc++.h>
using namespace std;
const int N = 101010;
int n;
struct Node{int x,y;}s[N];

int q[N];
int top;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++)  cin>>s[i].x>>s[i].y;
	sort(s+1,s+1+n,[](Node a,Node b)
    {
        return a.x < b.x;
    });
	for(int i = 1;i <= n;i++)
	{
		if(!top||q[top]>s[i].y) q[++top]=s[i].y;
		else{
			int l=1,r=top,pos= top;
			while(l<=r)
            {
				int mid = l + r >> 1;
				if(s[i].y>=q[mid]){
					pos = min(pos,mid);
					r=mid-1;
				}
				else l=mid+1;
			}
			q[pos]=s[i].y;
		}
	}
	cout<<top<<"\n";
}