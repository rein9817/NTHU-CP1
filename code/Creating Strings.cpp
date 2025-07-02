#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<string> ans;
    sort(s.begin(),s.end());
    int cnt=0;
    do{
        cnt++;
        ans.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<cnt<<"\n";
    for(auto x:ans)
    {
        cout<<x<<"\n";
    }
}