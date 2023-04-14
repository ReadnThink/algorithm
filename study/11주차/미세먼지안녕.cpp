#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
typedef long long ll;
using namespace std;

int n, m, t,x1,y1,x2,y2, home[51][51], temp[51][51];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void test(){
	cout << '\n';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << home[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input(){
	bool find = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> home[i][j];
			if(home[i][j] == -1 && find){
				find = false;
				y1 = i;
				x1 = j;

				y2 = i + 1;
				x2 = j;
			}
		}
	}
}

int dfs(int y, int x){
	int cnt = 0;
	// 초기에 있던 미세먼지로는 이동하지 않음
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(nx < 0 || ny < 0 || ny >= n || nx >= m || home[ny][nx] == -1) continue;
		temp[ny][nx] += home[y][x] / 5;
		cnt++;
	}
	return cnt;
}

void give(int t[51][51]){
	// 옮기기
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			home[i][j] += t[i][j];
		}
	}
}

void move(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(home[i][j] != -1 && home[i][j] != 0){
				int cnt = dfs(i,j);
				home[i][j] -= (home[i][j] / 5) * cnt;
			}
		}
	}
	give(temp);
}

void clean(){
	//위에 반시계
	int a = home[y1][m -1];
	int b = home[0][0];
	int c = home[0][m -1];

	//아래
	for(int x = m -1; x > 1; x--)home[y1][x] = home[y1][x - 1];
	//위
	for(int x = 0; x < m - 1; x++)home[0][x] = home[0][x + 1];
	//오른
	for(int y = 0; y < y1; y++)home[y][m-1] = home[y + 1][m-1];
	// 왼
	for(int y = y1 - 1; y > 0; y--)home[y][0] = home[y - 1][0];
	home[y1 - 1][m-1] = a;
	home[1][0] = b;
	home[0][m - 2] = c;

	//아래 시계방향
	a = home[y2][m -1];
	b = home[n - 1][0];
	c = home[n-1][m -1];
	//위
	for(int x = m - 1; x > 1; x--)home[y2][x] = home[y2][x - 1];
	//아래
	for(int x = 0; x < m -1; x++)home[n-1][x] = home[n-1][x + 1];
	//오른
	for(int y = n-1; y > y2; y--)home[y][m-1] = home[y - 1][m-1];
	//왼
	for(int y = y2 + 1; y < n -1; y++)home[y][0] = home[y + 1][0];
	home[y2 + 1][m - 1] = a;
	home[n - 2][0] = b;
	home[n-1][m - 2] = c;

	//청소기 바로앞은 0이다
	home[y1][x1 + 1] = 0;
	home[y2][x2 + 1] = 0;
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> t;
	input();
	while(t--){
		memset(temp, 0, sizeof(temp));
		move();
		clean();
		// test();
	}

	int ret = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(home[i][j] != -1) ret += home[i][j];
		}
	}
	cout << ret << '\n';
	return 0;
}