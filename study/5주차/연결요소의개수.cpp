#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <queue>

using namespace std;
int N,M, ret, visited[100004];
vector<int> km,price, adj[10004];

const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

// void test_print(){
// 	for(int i = N; i < N + 10; i++){
// 		for(int j = M; j < M + 10; j++){
// 			cout << visited[i][j] << ' ';
// 		}
// 		cout << '\n';
// 	}
// }

void Input(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}


void Solution(int node){
	visited[node] = true;

	for(int value : adj[node]){
		if(!visited[value]) Solution(value);
	}
}


void Solve(){
	Input();
	for(int i = 1; i <= N; i++){
		if(!visited[i]){
			Solution(i);
			ret++;
		}
	}
	// Test_print();
	cout << ret << '\n';
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Solve();
}