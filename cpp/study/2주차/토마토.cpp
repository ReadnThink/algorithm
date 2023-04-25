#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
int N,M,y,x,res, map[1004][1004],visited[1004][1004];
queue<pair<int,int>> q;
vector<pair<int,int>> startList;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void bfs(){
	while(q.size()){
		tie(y,x) = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];

			if(nx < 0 || ny < 0 || nx >= M || ny >= N || map[ny][nx] == -1) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny,nx});
			res = max(res,visited[ny][nx]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	bool check = false;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
			if(map[i][j] == 0) check = true;
			if(map[i][j] == 1) startList.push_back({i,j});
		}
	}

	if(!check) {
		cout << 0 << "\n";
		exit(0);
	}

	for(auto p : startList){
		q.push({p.first,p.second});
		visited[p.first][p.second] = 1;
	}
	bfs();

	// cout << "\n----------------------\n";

	// for(int i = 0; i < N; i++){
	// 	for(int j = 0; j < M; j++){
	// 		cout << visited[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(visited[i][j] == 0 && map[i][j] != -1) {
				res = 0;
			}
		}
	}
	
	cout << res - 1 << "\n";
}
