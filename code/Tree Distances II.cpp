#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=2e5+1;
vector<int> tree[mx];
ll dp[mx],res[mx];
int n;

void dfs(int u,int p,int depth){
	dp[u]++;
	res[1]+=depth;
	for(auto& v:tree[u]){
		if(v!=p){
			dfs(v,u,depth+1);
			dp[u]+=dp[v];
		}
	}
}

void dfs(int u,int p)
{
	for(auto& v:tree[u]){
		if(v!=p){
			res[v]=res[u]+n-dp[v]-dp[v];
			dfs(v,u);
		}
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,-1,0);
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		cout<<res[i]<<" ";
	}
	cout<<'\n';
 
}