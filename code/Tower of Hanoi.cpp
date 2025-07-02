#include <bits/stdc++.h>
using namespace std;
int cnt=0;
vector<string> ans;
void hanoi(int level,char a,char b,char c)
{
    if(level==0) return;
    hanoi(level-1,a,c,b);
    string s;
    s+=a;
    s+=" ";
    s+=c;
    ans.push_back(s);
    hanoi(level-1,b,a,c);
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,'1','2','3');
    cout<<ans.size()<<"\n";
    for(auto x:ans)
    {
        cout<<x<<"\n";
    }
}