#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,ret,arr[51][51], visited[51][51];

const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};

void input(){
	cin >> n >> m;
	string temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		for(int j = 0; j < m; j++){
			if(temp[j] >= 'A' && temp[j] <= 'Z') arr[i][j] = -1;
			else arr[i][j] = temp[j] - '0';
		}
	}
}

void output(){
	cout << ret << '\n';
	// cout << '\n';

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << visited[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
}

pair<int,int> moves(int dir, int y, int x, int num){
	int ny = y;
	int nx = x;
	if(dir == 0){
		ny -= num;
	}else if(dir == 1){
		nx += num;
	}else if(dir == 2){
		ny += num;
	}else if(dir == 3){
		nx -= num;
	}

	return {ny, nx};
}

void dfs(int y, int x){
	ret = max(ret, visited[y][x]);
	int num = arr[y][x];

	for(int i = 0; i < 4; i++){
		pair<int,int> next = moves(i,y,x,num);
		int ny = next.first;
		int nx = next.second;

		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(arr[ny][nx] < 0) continue;
		if(visited[ny][nx]){
			cout << -1 << '\n';
			exit(0);
		}
		visited[ny][nx] = visited[y][x] + 1;
		dfs(ny,nx);
		visited[ny][nx] = 0;
	}
}

int main(){
	input();
	visited[0][0] = 1;
	dfs(0,0);
	output();
}