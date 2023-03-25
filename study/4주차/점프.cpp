#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;
int N,ret, visited[104][104];
vector<int> board[104];
vector<pair<int,int>> dp[104][104];

void input(){
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int tmp; cin >> tmp;
			board[i].push_back(tmp);
		}
	}
}

void dfs(int y, int x){
	visited[y][x] = 1;
	dp[y][x].push_back({y,x});

	if(y == N - 1 && x == N - 1){
		ret++;
		cout << "\n\n---------------\n\n";
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cout << visited[i][j] << " ";
			}
			cout << "\n";
		}
		return;
	}
	 if(board[x][y] == 0) return;

	for(int i = 0; i < 2; i ++){
		int ny = -1;
		int nx = -1;
		if(i == 0){
			//오른쪽
			ny = y;
			nx = x + board[y][x];
		}else{
			//아래
			ny = y + board[y][x];
			nx = x;
		}

		if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if(visited[ny][nx]){
			dfs(dp[ny][nx].front().first, dp[ny][nx].front().second);
		}
		dp[ny][nx].push_back({ny,nx});

		dfs(ny,nx);

		// visited[ny][nx] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	dfs(0,0);

	cout << ret << '\n';
}