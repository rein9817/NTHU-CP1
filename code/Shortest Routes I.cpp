#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
#define int long long 
int d[maxn];
vector<pair<int, int>> edge[maxn];

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    d[source] = 0;
    while (!pq.empty()) {
        auto [dist, v] = pq.top();
        pq.pop();

        if (d[v] < dist) continue;

        for (auto [u, weight] : edge[v]) {
            if (d[u] > d[v] + weight) {
                d[u] = d[v] + weight;
                pq.push({d[u], u}); // {distance, node}
            }
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    memset(d,0x3f,sizeof(d));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}
