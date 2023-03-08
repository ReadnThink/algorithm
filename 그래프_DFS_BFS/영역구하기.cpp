#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int max_n = 104;
int x, y, k, ret, visited[max_n][max_n], arr[max_n][max_n];
int a,b,c,d;
vector<int> v;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int cy, int cx){
	visited[cy][cx] = 1;
	arr[cy][cx] = 1;
	for(int i = 0; i < 4; i++){
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if(nx < a || nx >= c || ny < b || ny >= d) continue;
		if(visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int dfs_cnt(int cy, int cx, int sum){

	visited[cy][cx] = 1;
	arr[cy][cx] = 1;
	
	ret++;

	for(int i = 0; i < 4; i++){
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if(ny < 0 || nx < 0 || ny >= y || nx >= x) continue;
		if(visited[ny][nx] == 0 && arr[ny][nx] != 1){
			dfs_cnt(ny, nx, sum + 1);
		}

	}
	return sum;
}

int main(){
	cin >> y >> x >> k;

	for(int i = 0; i < k; i++){
		cin >> a >> b >> c >> d;
		dfs(b,a);
		memset(visited, 0, sizeof(visited));
	}
	int cnt = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(arr[i][j] == 0){
				dfs_cnt(i,j,1);
				v.push_back(ret);
				cnt++; ret = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for(auto i : v) cout << i << " ";
};