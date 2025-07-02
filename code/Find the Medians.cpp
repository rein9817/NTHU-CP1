#include <bits/stdc++.h>
using namespace std;

int main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); // IO 優化
    int n; priority_queue<int> left; priority_queue<int, vector<int>, greater<int>> right;
    left.push(INT_MIN); right.push(INT_MAX); // avoid empty queues
    int x;
    cin>>x;
    for(int i=1;i<=x;i++) {
        cin>>n;
        if (n < left.top()) {
            if (left.size() > right.size()) right.push(left.top()), left.pop();
            left.push(n);
        } else if (n > right.top()) {
            if (left.size() < right.size()) left.push(right.top()), right.pop();
            right.push(n);
        } else if (left.size() < right.size()) left.push(n);
        else right.push(n);
        if (left.size() > right.size()) cout << left.top() << '\n';
        else if (left.size() < right.size()) cout << right.top() << '\n';
        else cout << (left.top() + right.top()) / 2 << '\n';
    }
    return 0;
}