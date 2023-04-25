#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
int T,N,M,K, visited[54][54], board[54][54];
string s;
vector<int> ret;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void input(){
	for(int i = 0; i < K; i++){
		int tmp_x,tmp_y; cin >> tmp_x >> tmp_y;
		board[tmp_y][tmp_x] = 1;
	}
}

void test_print(){
	cout << "\n\n\n";
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

void dfs(int y, int x){
	visited[y][x] = 1;

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
		if(board[ny][nx] == 0) continue;
		dfs(ny,nx);
	}
}

void start(){
	cin >> T;
	while(T--){
		memset(visited,0,sizeof(visited));
		memset(board,0,sizeof(board));
		cin >> M >> N >> K;

		input();

		int cnt = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(!visited[i][j] && board[i][j] == 1){
					dfs(i,j);
					cnt++;
				}
			}
		}
		ret.push_back(cnt);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	start();
	for(auto i : ret) cout << i << '\n';
}