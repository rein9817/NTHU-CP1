#include <bits/stdc++.h>
using namespace std;
#define vec vector
#define int long long
 
constexpr int mod = 1e9 + 7;
 
template<typename T> using mtx = vector<vector<T>>;


template<typename T>
mtx<T> operator*(const mtx<T> &a, const mtx<T> &b) {
    int n = a.size(), m = b.front().size(), k = b.size();
    mtx<T> r(n, vector<T>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int z = 0; z < k; z++)
                r[i][j] = (r[i][j] + a[i][z] * b[z][j] % mod) % mod;
    return r;
}
 
int n, m, k;
mtx<int> v, one;
 
int fpow() {
	one.assign(n, vec<int>(n));
	for(int i = 0; i < n; i++) one[i][i] = 1;
	for(; k; k >>= 1, v = v * v) {
		if(k & 1) one = one * v;
	}
	return one[0][n - 1];
}
 
signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m>>k;
	v.assign(n, vec<int>(n, 0));
	while(m--) 
    {
		int x, y;
		cin >> x >> y;
		v[x-1][y-1]++;
	}
	cout << fpow();
}