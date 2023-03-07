#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int max_n = 104;
int n, ret, sum, visited[max_n][max_n], a[max_n][max_n], b[max_n][max_n];

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
	visited[y][x] = 1;

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) continue;
		if(b[ny][nx] == 0) continue;
		dfs(ny,nx);
	}
}

int main(){
	cin >> n;
	int cnt = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			cnt = max(cnt,a[i][j]);
		}
	}

	while(cnt--){
		// copy(&a[0][0], &a[0][0]+max_n, &visited[0][0]);
		// cout << cnt << "cnt \n";

		memset(visited, 0, sizeof(visited));
		sum = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				b[i][j] = a[i][j];
			}
		}	

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(b[i][j] <= cnt){
					b[i][j] = 0;
				}
				// cout << b[i][j] << " ";
			}
			// cout << "\n";
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!visited[i][j] && b[i][j]) {
					dfs(i,j); sum++;
					ret = max(ret, sum);
				}
			}
		}	
	}
	cout << ret << "\n"	;
}