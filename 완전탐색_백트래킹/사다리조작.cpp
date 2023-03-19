#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M, H, ret = INT_MAX, visited[35][35];

bool check(){
	for(int i = 1; i <= N; i++){
		int pos = i;
		for(int j = 1; j <= H; j++){
			if(visited[j][pos]) pos++;
			else if (visited[j][pos - 1]) pos--;
		}
		if(pos != i) return false;
	}
	return true;
}

void dfs(int y, int cnt){
	if(cnt > 3 || cnt >= ret) return;
	if(check()){
		ret = min(ret,cnt);
		return;
	}
	for(int i = y; i <= H; i++){
		for(int j = 1; j <= N; j++){
			if(visited[i][j] || visited[i][j+1] || visited[i][j-1]) continue;
			visited[i][j] = 1;
			dfs(i,cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> H;

	for(int i = 0; i < M; i++){
		int a, b; cin >> a >> b;
		// a:가로  b : 세로  b -> b+1 로 이어지는 선 
		visited[a][b] = 1;
	}

	dfs(1,0);
	if(ret == INT_MAX) ret = -1;
	cout << ret << "\n";
}