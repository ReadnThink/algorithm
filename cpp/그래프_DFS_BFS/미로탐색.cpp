#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, ret, visited[104][104], a[104][104];

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int y, int x){
	visited[y][x] = 1;
	queue<pair<int,int>> q;
	q.push({y,x});

	while(q.size()){
		tie(y,x) = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(nx < 0 || ny < 0 || nx >= m || ny >= n || a[ny][nx] == 0) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
			
		}
	}
}

int main(){
	scanf("%d %d", &n, &m); 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]);
		}
	}
	bfs(0,0);
	cout << visited[n - 1][m - 1];
	// cout << "\n";
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << visited[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
}