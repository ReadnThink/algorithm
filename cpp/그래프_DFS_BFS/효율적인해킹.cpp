#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N,M, A,B, ret, dp[100005];
vector<int> adj[100005];
int visited[100005];


int dfs(int here){
	visited[here] = 1;

	int res = 1;
	for(int there : adj[here]){
		if(visited[there]) continue;
		res += dfs(there);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N>> M;

	for(int i = 0; i < M; i++){
		cin >> A >> B;
		adj[B].push_back(A);
	}

	for(int i = 1; i <= N; i++){
		memset(visited,0,sizeof(visited));
		dp[i] = dfs(i);
		ret = max(dp[i], ret);
	}

	for(int i = 1; i <= N; i++){
		if(ret == dp[i]) cout << i << " ";
	}

}


