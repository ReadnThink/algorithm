#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int n,m, ret, table[1025][1025], visited[1025][1025];
int s_x, s_y, e_x, e_y;
vector<int> v;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void test_print(){
	cout << '\n';

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << table[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "-------------visited------------\n";

	for(int i = 1; i <= n + 1; i++){
		for(int j = 1; j <= n + 1; j++){
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}

int dfs(int y, int x){
	visited[y][x] = 1;
	ret += table[y][x];
	if(y == e_y && x == e_x) {
		return 0;
	}

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny > n || nx < 0 || nx > n || visited[ny][nx]) continue;
		if(ny < s_y || ny > e_y || nx < s_x || nx > e_x) continue;

		dfs(ny,nx);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> table[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		cin >> s_y >> s_x >> e_y >> e_x;
		dfs(s_y, s_x);
		v.push_back(ret);
		// test_print();
		memset(visited,0,sizeof(visited));
		ret = 0;
	}
	for(auto i : v) cout << i << '\n';
	
}