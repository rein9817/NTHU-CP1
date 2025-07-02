#include <bits/stdc++.h>
using namespace std;
 
#define fast ios::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
#define f first
#define s second
#define MOD 998244353
#define LOGN 21
#define MAXN 105
#define int long long
 
int temp[MAXN][MAXN], dist[MAXN][MAXN], sell[MAXN][MAXN];
int N, market[MAXN][1005][2];
const ll INF = LLONG_MAX / 2;
bool check(int K) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            temp[i][j] = - sell[i][j] + K * min(dist[i][j], INF / K);
    }
 
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                temp[i][j] = min(temp[i][j], temp[i][k] + temp[k][j]);
        }
    }
 
    for (int i = 1; i <= N; i++) {
        if (temp[i][i] <= 0)
            return true;
    }
    return false;
}
 
signed main() 
{
    fast
    int M, K;
    cin >> N >> M >> K;
 
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++)
            dist[i][j] = INF;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++)
            cin >> market[i][j][0] >> market[i][j][1];
    }
    for (int i = 0; i < M; i++) {
        int from, to, T;
        cin >> from >> to >> T;
        dist[from][to] = min(dist[from][to], T);
    }
 
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= K; k++) {
                if (market[j][k][1] != -1 && market[i][k][0] != -1)
                    sell[i][j] = max(sell[i][j], market[j][k][1] - market[i][k][0]);
            }
        }
    }
 
    int L = 1;
    int R = 1e9;
    int ans = -1;
    while (R >= L) {
        int mid = L + (R-L) / 2;
        if (check(mid)) {
            ans = mid;
            L = mid + 1;
        } else
            R = mid - 1;
    }
    cout << R << "\n";
}