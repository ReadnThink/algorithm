#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <queue>

using namespace std;
int T,N,M,ret,grid[104][104],visited[104][104];

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

// void test_print(){
// 	for(int i = N; i < N + 10; i++){
// 		for(int j = M; j < M + 10; j++){
// 			cout << visited[i][j] << ' ';
// 		}
// 		cout << '\n';
// 	}
// }

void dfs(int y, int x){
	// cout << y <<" : " << x << "\n";
	ret++;

	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];

		if(ny < N || nx < M || ny >= N + 10 || nx >= M + 10 || visited[ny][nx]) continue;
		dfs(ny,nx);
	}
}

void Input(){
	cin >> T;

	while(T--){
		cin >> M >> N;

		for(int i = N; i < N + 10; i++){
			for(int j = M; j < M + 10; j++){
				if(!visited[i][j]){
					dfs(i,j);
				}
			}
		}
	}
	// test_print();
	cout << ret << '\n';
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