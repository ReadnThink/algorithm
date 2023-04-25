#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};
int N, M,ret, visited[1504][1504];
bool is_meet;
vector<string> board;
vector<pair<int,int>> start; 
string s;

void dfs(int y, int x){
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		if(board[ny][nx] == 'X'){
			board[ny][nx] = '.'	;
			return;
		}
		else{
			dfs(ny,nx);
		}
	}
}

void find_start(int y, int x){

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
		visited[ny][nx] = visited[y][x] + 1;
		if(board[ny][nx] == 'L'){
			is_meet = true;
			return;
		}
		else if(board[ny][nx] == '.'){
			find_start(ny,nx);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		board.push_back(s);
		for(int j = 0; j < M; j++){
			if(s[j] == 'L') start.push_back({i,j});
		}
	}

	while(!is_meet){
		ret++;
		memset(visited,0,sizeof(visited));
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(board[i][j] == '.' && !visited[i][j]) {
					visited[i][j] = 1;
					dfs(i,j);
				}
			}
		}
		memset(visited,0,sizeof(visited));
		visited[start[0].first][start[0].second] = 1;
		find_start(start[0].first,start[0].second);

		// for(int i = 0; i < N; i++){
		// 	for(int j = 0; j < M; j++){
		// 		cout << visited[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// cout << "\n";cout << "\n";
		// for(int i = 0; i < N; i++){
		// 	for(int j = 0; j < M; j++){
		// 		cout << board[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
	}
	cout << ret << "\n";
	// for(auto i : start) cout << i.first << " : " << i.second << "\n";
}
