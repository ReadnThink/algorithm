#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

int N,ret = 999999999, visited[15][15];
int board[15][15];

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int visit(int y, int x){
	visited[y][x] = 1;
	int s = board[y][x];
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		s += board[ny][nx];
	}
	return s;
}

void visit_cancle(int y, int x){
	visited[y][x] = 0;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}

bool check(int y, int x){
	if(visited[y][x]) return 0;

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) return 0;
	}
	return 1;
}

void dfs(int depth, int sum){
	if(depth == 3) {
		ret = min(ret, sum);
		return;
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(check(i,j)){
				dfs(depth + 1, sum + visit(i,j));
				visit_cancle(i,j);
			}
		}
	}

}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}

	dfs(0,0);
	
	cout << ret << "\n";
}
