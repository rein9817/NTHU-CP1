#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    priority_queue<int,vector<int>,greater<int>> pq;
    deque<int> dq;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x; 
            dq.push_back(x);
        }
        else if(op==2)
        {   
            if(pq.size())
            {
                cout<<pq.top()<<endl;
                pq.pop();
            }
            else 
            {
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        }
        else {
            while(dq.size())
            {
                pq.push(dq.front());
                dq.pop_front();
            }
        }
    }
}