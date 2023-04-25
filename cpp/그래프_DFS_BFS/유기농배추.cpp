#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

const int max_num = 54;
int t, n, m, k, ret, visited[max_num][max_num], a[max_num][max_num];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void dfs(int y, int x){
	visited[y][x] = 1;

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(nx < 0 || ny < 0 || nx >= m || ny >= n || a[ny][nx] == 0) continue;
		if(visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main(){
	cin >> t;

	while(t--){
		
		cin >> m >> n >> k;

		for(int i = 0; i < k; i++){
			int x, y; cin >> x >> y;
			a[y][x] = 1;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!visited[i][j] && a[i][j] == 1){
					dfs(i, j);
					ret++;
				}
				// cout << a[i][j] << " ";
			}
			// cout << "\n";
		}
		cout << ret << "\n";
		ret = 0;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
	}
}