#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int max_n = 16;
int n,ret, arr[max_n][max_n];

void dfs(int state, int y, int x){
	if(y == n - 1 && x == n - 1){
		ret++;
		return;
	}

	bool canMoveX = x + 1 < n && arr[y][x + 1] == 0;
	bool canMoveY = y + 1 < n && arr[y + 1][x] == 0;

	//가로, 세로 이동
	if(canMoveX && state != 1){
		dfs(0, y, x + 1);
	}
	if(canMoveY && state != 0){
		dfs(1, y + 1, x);
	}
	//대각선이동
	if(canMoveX && canMoveY && arr[y + 1][x + 1] == 0){
		dfs(2, y + 1, x + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}

	dfs(0,0,1);
	cout << ret << '\n';
	return 0;
}