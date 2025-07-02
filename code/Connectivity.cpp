#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, k, fa[N], p[N], a[N], b[N], cnt[N], ans[N];

int find(int x) 
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) 
{
    a = find(a), b = find(b);
    if(a == b) return;
    fa[a] = b;
}

int main() 
{
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
    }
    for(int i = 1; i <= n; i++) p[i] = find(i);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
    }
    for(int i = 1; i <= n; i++) b[i] = find(i), a[i] = i;
    sort(a + 1, a + 1 + n, [&](int x, int y) {return b[x] < b[y];});
    for(int i = 1, j; i <= n; i = j + 1) 
    {
        j = i;
        while(j + 1 <= n && b[a[j + 1]] == b[a[i]]) j++;
        for(int k = i; k <= j; k++) cnt[p[a[k]]]++;
        for(int k = i; k <= j; k++) ans[a[k]] = cnt[p[a[k]]];
        for(int k = i; k <= j; k++) cnt[p[a[k]]]--;
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    cout<<"\n";
}