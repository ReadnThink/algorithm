#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <float.h>
#include <cmath>
#include <cstring>

using namespace std;
int n,ret, dp[100004], visited[100004];
vector<int> adj[100004];

void dfs(int node){
	visited[node] = 1;
	for(auto value : adj[node]){
		if(!visited[value]){
			dp[value] = node;
			dfs(value);
		}	
	}
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n;
	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for(int i = 2; i <= n; i++){
		cout << dp[i] << '\n';
	}
	return 0;
}