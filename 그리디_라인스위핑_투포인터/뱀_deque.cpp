#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;
int ret,y,x, n, k, l,idx,snake_size,dir = 0, board[101][101], visited[101][101];
vector<pair<int, char>> directions;
deque<pair<int,int>> dq;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void test(){
	cout << '\n';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}


void move(){
	dq.push_back({0,0});
	while(dq.size()){
		test();
		ret++;
		tie(y,x) = dq.front();
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if(ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx]) break;

		if(!board[ny][nx]){
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}else board[ny][nx] = 0;

		visited[ny][nx] = 1;
		dq.push_front({ny,nx});
		if(ret == directions[idx].first){
			dir = (dir + directions[idx].second) % 4;
			idx++;
		}

	}
}
int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> n >> k;

	for(int i = 0; i < k; i++){
		int y,x; cin >> y >> x;
		board[y - 1][x - 1] = 1;
	}

	cin >> l;
	for(int i = 0; i < l; i++){
		int time; char direction; cin >> time >> direction;
		if(direction == 'D') directions.push_back({time, 1});
		else directions.push_back({time, 3});
	}

	move();
	
	cout << ret << '\n';
	return 0;
}