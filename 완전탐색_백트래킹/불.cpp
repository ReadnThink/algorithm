#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

queue<pair<int,int>> q;
int R,C,y,x,res;
string s;
vector<string> v;
vector<pair<int,int>> startList;
vector<pair<int,int>> fireList;
bool fireCheck;
int visited[1004][1004];
int visited_fire[1004][1004];

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void bfs(){
	while(q.size()){
		tie(y,x) = q.front(); q.pop();
		if(y == 0 || x == 0 || y == R -1 || x == C -1) res = min(res, visited[y][x]);
		for(int i = 0; i < 4; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];

			if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) continue;
			if(v[ny][nx] == 'F' || v[ny][nx] == '#') continue;
			visited[ny][nx] = visited[y][x] + 1;
			//불이 더 낮으면 지나간다.
			if(fireCheck){
				if(visited[ny][nx] >= visited_fire[ny][nx]) continue;
			}
			//탈출일 경우 최솟갑 저장
			if(ny == 0 || nx == 0 || ny == R -1 || nx == C -1) res = min(res, visited[ny][nx]);
			q.push({ny,nx});
		}
	}
}

void bfs_fire(){
	while(q.size()){
		tie(y,x) = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];

			if(ny < 0 || nx < 0 || ny >= R || nx >= C || visited_fire[ny][nx]) continue;
			if(v[ny][nx] == 'F' || v[ny][nx] == '#') continue;
			visited_fire[ny][nx] = visited_fire[y][x] + 1;
			q.push({ny,nx});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	res = 999999999;
	for(int i = 0; i < R; i++){
		cin >> s;
		v.push_back(s);
		for(int j = 0; j < C; j++){
			if(v[i][j] == 'J') startList.push_back({i,j});
			//불이 없는경우 체크를 해야한다.
			if(v[i][j] == 'F') {
				fireCheck = true;
				fireList.push_back({i,j});
			}
		}
	}

	//불먼저 나야 다른길을 선택할 수 있다.	
	for(auto i : fireList){
		q.push({i.first,i.second});
		visited_fire[i.first][i.second] = 1;
	}
	bfs_fire();

	for(auto i : startList){
		q.push({i.first,i.second});
		visited[i.first][i.second] = 1;
	}
	bfs();

	
	// for(int i = 0; i < R; i++){
	// 	for(int j = 0; j < C; j++){
	// 		cout << visited_fire[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	if(res == 999999999) {
		cout << "IMPOSSIBLE" << "\n";
		exit(0);
	}
	cout << res << "\n";
}
