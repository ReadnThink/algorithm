#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

const int V = 304;
int N, l, ret, fromX_idx, fromY_idx, toX_idx, toY_idx;
int visited[V][V], a[V][V];
vector<int> v;

const int dx[] = {1,2,2,1,-1,-2,-2,-1};
const int dy[] = {-2,-1,1,2,2,1,-1,-2};


void bfs(int y, int x){
	queue<pair<int,int>> q;	
	q.push({y,x});
	visited[y][x] = 1;

	while(q.size()){
		tie(y, x) = q.front(); q.pop();
		if(y == toY_idx && x == toX_idx) {
			// cout << "도착했습니다 " << a[y][x] << "\n";
			ret = a[y][x];
			return;
		}


		for(int i = 0; i < 8; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
			if(visited[ny][nx] == 1) continue;
			
			visited[ny][nx] = 1;
			a[ny][nx] = a[y][x] + 1;
			
			q.push({ny, nx});
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> l;
		cin >> fromY_idx >> fromX_idx;	
		cin >> toY_idx >> toX_idx;
	
		bfs(fromY_idx, fromX_idx);
		v.push_back(ret);
		
		memset(visited, 0, sizeof(visited));
		memset(a, 0, sizeof(a));
		ret = 0;
	}
	// for(int i = 0; i < l; i++){
	// 	for (int j = 0; j < l; j++){
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	for(auto i : v) cout << i << "\n";
}