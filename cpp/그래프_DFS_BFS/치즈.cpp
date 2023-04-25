#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0 ,-1 };

int N, M, res,res_map, map[104][104], visited[104][104];
bool check = false, loop = true;
vector<pair<int,int>> fromAir;


void DFS(int y, int x){
	if(map[y][x] == 1) {
		visited[y][x] = 2;
		return;
	}

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		DFS(ny, nx);
	}
}

void DFS_AIR(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= N || nx >= M) {
			//범위를 벗어나면
			check = true;
			continue;
		}
		if(visited[ny][nx]) continue;
		if(map[ny][nx] == 0) {
			visited[ny][nx] = 1;
			DFS_AIR(ny, nx);
		}
	}
}

/*
	1. DFS_AIR로 치즈 밖에있는 0을 찾아 벡터에 넣는다.
	2. DFS_AIR를 돌면서 치즈 바깥쪽 1을 찾아 visited에 2로 채워넣는다.
	3. visited가 2인곳을 map에서 0으로 바꿔준다
		- 바꿔줄때 cnt++을 한다.
		- 변경된 것이 없으면 while문을 종료한다.

	DFS_AIR와 DFS를 사용해서 불필요하게 2개나 DFS를 만들었다.
	하나의 DFS로 해결할 방법을 생각해보자

	***********************************************************
	1. dfs를 한번만 호출하면 치즈 바깥쪽만 돌게된다
		- dfs를 칸마다 했기때문에 치즈 안쪽까지 들어갔떤것.
	2. 바깥쪽으로부터 접근한 치즈가 1이면 vector에 넣어서 
		vector에 있는 인덱스들만 map을 0으로 만들 수도 있다.
*/

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}

	while(true){
		res++;

		// 치즈 밖 확인하기
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(map[i][j] == 0 && visited[i][j] == 0) {
					visited[i][j] = 1;
					DFS_AIR(i, j);
					if(check) fromAir.push_back({i,j});
					check = false;
				}
			}
		}
		
		memset(visited, 0, sizeof(visited));

		// 치즈 녹이기
		for(pair<int,int> p : fromAir){
			if(map[p.first][p.second] == 0 && visited[p.first][p.second] == 0) {
				DFS(p.first, p.second);
			}
		}

		// map에 반영하기
		bool isChange = false;
		int cnt = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(visited[i][j] == 2) {
					cnt++;
					map[i][j] = 0;
					isChange = true;
				}
			}
		}
		if(cnt != 0) res_map = cnt;
		if(!isChange) break;

	}
	cout << res - 1 << "\n";
	cout << res_map << "\n";
}


