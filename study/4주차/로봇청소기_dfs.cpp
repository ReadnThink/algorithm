#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
int N,M,s_x,s_y,ret,cnt, dt, visited[54][54], board[54][54];

const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};

void input(){
	cin >> N >> M;
	cin >> s_y >> s_x >> dt;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}
}

void dfs(int y, int x, int direction){
	
	if(board[y][x] == 0){
		board[y][x] = 2;
		ret++;
	}

	//청소할 곳이 있는지 확인하기 위함
	// 청소
	for(int i = 0; i < 4; i++){
		int next_d = ((direction + 3) - i) % 4;
		int ny = y + dy[next_d];
		int nx = x + dx[next_d];
		if(ny < 0 || nx < 0 || ny >= N || nx >= M || board[ny][nx] != 0) {
			continue;
		}
		if(board[ny][nx] == 0){
			dfs(ny, nx, next_d);
		}
	}

	//청소할 곳이 없다면 후진
	int by = y + dy[(direction + 2) % 4];
	int bx = x + dx[(direction + 2) % 4];
	if(by < 0 || bx < 0 || by >= N || bx >= M) {
		return;
	}
	// if(board[by][bx] == 0 || board[by][bx] == 2) 	dfs(by, bx, direction);
	
	if(board[by][bx] == 1){
		//벽이라면 ret 출력 후 종료
		cout << ret << "\n";
		exit(0);
	}
	//벽이 아니면 다시 dfs
	dfs(by, bx, direction);
}
	
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	dfs(s_y,s_x, dt);
}