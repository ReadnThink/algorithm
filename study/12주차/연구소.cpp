#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int n, m,ans = -1, arr[10][10], visited[10][10], temp[10][10];
vector<pair<int,int>> virus, rooms;
vector<int> walls;
const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};

void input(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 2) virus.push_back({i,j});
			if(arr[i][j] == 0) rooms.push_back({i,j});
			// printf("%d",arr[i][j]);
		}
		// printf("\n");
	}
}
void print(){
	printf("\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", temp[i][j]);
		}
        printf("\n");
	}
}

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		if(temp[ny][nx] == 1 || temp[ny][nx] == 2) continue;
		temp[ny][nx] = 3;
		visited[ny][nx] = 3;
		dfs(ny,nx);
	}
}

void solve(){
	memset(visited,0,sizeof(visited));
	memset(temp,0,sizeof(temp));

	// 복사
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			temp[i][j] = arr[i][j];
		}
	}
	// 벽 세우기
	for(auto i : walls){
		temp[rooms[i].first][rooms[i].second] = 1;
	}

    //test
    // print();

	//탐색
	for(auto i : virus){
		visited[i.first][i.second] = 1;
		temp[i.first][i.second] = 1;
		dfs(i.first,i.second);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(temp[i][j] == 0)	cnt++;
		}
	}
	ans = max(ans, cnt);
}
// 4 4
// 1 1 1 0 
// 1 1 1 0
// 1 1 1 0
// 1 1 1 0
//벽을 세울곳의 조합을 구함
void combi(int start, int depth){
	if(depth == 3){
		solve();
		return;
	}
	for(int candi = start; candi < rooms.size(); candi++){
		walls.push_back(candi);
		combi(candi + 1, depth + 1);
		walls.pop_back();
	}
}

int main(){
	input();
	combi(0,0);
	printf("%d", ans);
	// print();
}