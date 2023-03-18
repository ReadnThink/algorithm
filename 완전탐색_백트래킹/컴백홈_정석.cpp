#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

int N,M,K,ret ,visited[10][10];
char board[10][10];
vector<int> sum_list;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int dfs(int y, int x){
	if(visited[0][M - 1]){
		if(K == visited[0][M-1]) return 1;
		return 0;
	}

	int sum = 0;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] || board[ny][nx] == 'T') continue;
		visited[ny][nx] = visited[y][x] + 1;
		sum += dfs(ny,nx);	
		visited[ny][nx] = 0;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}
	visited[N-1][0] = 1;
	ret = dfs(N-1,0);
	cout << ret << "\n";
}