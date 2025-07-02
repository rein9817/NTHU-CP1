#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y, vx, vy;
        cin >> n >> m >> x >> y >> vx >> vy;

        if ((vx == -1 && x == 0) || (vx == 1 && x == n) || (vy == -1 && y == 0) || (vy == 1 && y == m)) {
            // If the particle hits a corner
            cout << n << " " << m << "\n";
        } else {
            int gcd_val = gcd(n, m);
            int dx = abs(x - n);
            int dy = abs(y - m);

            if ((dx % gcd_val == 0) && (dy % gcd_val == 0)) {
                // If the particle reaches a point with integer coordinates
                cout << x << " " << y << "\n";
            } else {
                // If the particle doesn't reach a point with integer coordinates
                cout << "-1\n";
            }
        }
    }

    return 0;
}
