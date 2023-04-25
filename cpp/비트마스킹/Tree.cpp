#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>

using namespace std;
int T,N,M,ret,grid[5][5],visited[100];
vector<int> adj[1005];

void DFS(int node){
	visited[node] = 1;

	for(int value : adj[node]){
		if(!visited[value]) DFS(value);
	}
	return;
}

void Input(){
	cin >> T;
	for(int i = 1; i <= T; i++){
		memset(visited,0,sizeof(visited));
		cin >> N;
		cin >> M;
		for(int j = 0; j < M; j++){
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int cnt = 0;
		for(int i = 1; i <= N; i++){
			if(!visited[i]){
				DFS(i);
				cnt++;
			}
		}
		if(cnt == 1 && M == N - 1) cout << "tree" << '\n';
		else cout << "graph" << '\n';
	}


}
void Test_print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}


void Solve(){
	Input();
	// Test_print();
	// cout << ret << '\n';
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Solve();
}