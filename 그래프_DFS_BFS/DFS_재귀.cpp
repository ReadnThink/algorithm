#include <iostream>
#include <vector>

using namespace std;

int n,m, ret;
int a[104][104];
int visited[104][104];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};


void dfs(int y, int x){
	cout << y << " : " << x << "\n";

	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if(a[ny][nx] == 1 && !visited[ny][nx]) dfs(ny, nx);
	}
}

// 5 5
// 1 0 1 0 1
// 1 1 0 0 1
// 0 0 0 1 1
// 0 0 0 1 1
// 0 1 0 0 0


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if(visited[i][j] == 0 && a[i][j] == 1){
				cout << i << " : " << j << "dfs가 시작됩니다. \n";
				dfs(i,j);
				ret++;
			}
		}
	}
	cout << ret << "\n";
}