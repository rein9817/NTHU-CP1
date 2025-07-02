#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7, m = 5e8 + 4;
signed main(){
    int n, ans = 0, l, r, gh;
    cin >> n;
    gh = sqrt(n);
    for(int i = 1; i <= gh; i++){
        l = n / i, r = n / (i + 1) + 1;
        ans += (((((((l - r + 1) % mod) * ((l + r) % mod)) % mod) * m) % mod) * i) % mod;
        ans %= mod;
    }
    for(int i = 1; i <= n / (gh + 1); i++){
        ans += (n / i) * i;
        ans %= mod;
    }
    cout << ans;
    return 0;
}