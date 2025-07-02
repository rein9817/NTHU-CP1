#include <bits/stdc++.h>
using namespace std;
vector<string> res(int n)
{
    if(n==1)
    {
        return {"0","1"};
    }
    auto temp=res(n-1);
    int m=temp.size();
    vector<string> ans;
    for(int i=0;i<m;i++)
    {
        ans.push_back("0"+temp[i]);
    }
    for(int i=m-1;i>=0;i--)
    {
        ans.push_back("1"+temp[i]);
    }
    return ans;
}
int main()
{
    int n; 
    cin>>n;
    auto ans=res(n);
    for(string temp:ans)
    {
        cout<<temp<<endl;
    }
}