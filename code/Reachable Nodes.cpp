#include <vector>
#include <iostream>
#include <stack>
#include <map>
#include <bitset>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
 
vector<bitset<50001> > nodes;
vector<bool> visii;
vector<vector<int> > adj;

void dfs(int nod)
{
    visii[nod] = 1;
    nodes[nod].set(nod);
    for(int i : adj[nod]){
        if(!visii[i]) dfs(i);
        nodes[nod] |= nodes[i];
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n);
    nodes.resize(n);
    visii.resize(n);
    for(int i = 0; i < m; i++){
        int da, a;
        cin >> da >> a;
        adj[da-1].push_back(a-1);
    }
    for(int i = 0; i< n; i++){
        if(!visii[i]) dfs(i);
    }
    
    for(int i = 0; i< n; i++){
        cout << nodes[i].count() << " ";
    }
}
