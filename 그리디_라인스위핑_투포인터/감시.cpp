#include <iostream>
#include <vector>

using namespace std;
int n,m, room[8][8], temp[8][8], ret = 987654321;
vector<pair<int,int>> cctv;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<pair<int,int>> extendCCTV(int depth, int dir){
	vector<pair<int,int>> _change;
	int y = cctv[depth].first;
	int x = cctv[depth].second;

	if(room[y][x] == 1){
		while(true){
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if(ny >= 0 && ny < n && nx >= 0 && nx < m && room[ny][nx] != 6){
				if(room[ny][nx] == 0){
					room[ny][nx] = 8;
					_change.push_back({ny,nx});
				}
				y = ny;
				x = nx;
			}else break;
		}
	}else if(room[y][x] == 2){
		for(int i = 0; i <= 2; i += 2){
			int _y = y;
			int _x = x;

			while(true){
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];

				if(ny >= 0 && ny < n && nx >= 0 && nx < m && room[ny][nx] != 6){
				if(room[ny][nx] == 0){
					room[ny][nx] = 8;
					_change.push_back({ny,nx});
				}
				_y = ny;
				_x = nx;
				}else break;
			}
		}
	}else if(room[y][x] == 3){
		for(int i = 0; i < 2; i++){
			int _y = y;
			int _x = x;

			while(true){
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];

				if(ny >= 0 && ny < n && nx >= 0 && nx < m && room[ny][nx] != 6){
				if(room[ny][nx] == 0){
					room[ny][nx] = 8;
					_change.push_back({ny,nx});
				}
				_y = ny;
				_x = nx;
				}else break;
			}
		}
	}else if(room[y][x] == 4){
		for(int i = 0; i < 3; i++){
			int _y = y;
			int _x = x;

			while(true){
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];

				if(ny >= 0 && ny < n && nx >= 0 && nx < m && room[ny][nx] != 6){
				if(room[ny][nx] == 0){
					room[ny][nx] = 8;
					_change.push_back({ny,nx});
				}
				_y = ny;
				_x = nx;
			}else break;
			}
		}
	}else if(room[y][x] == 5){
		for(int i = 0; i < 4; i++){
			int _y = y;
			int _x = x;

			while(true){
				int ny = _y + dy[(dir + i) % 4];
				int nx = _x + dx[(dir + i) % 4];

				if(ny >= 0 && ny < n && nx >= 0 && nx < m && room[ny][nx] != 6){
				if(room[ny][nx] == 0){
					room[ny][nx] = 8;
					_change.push_back({ny,nx});
				}
				_y = ny;
				_x = nx;
			}else break;
			}
		}
	}
	return _change;
}

void DFS(int depth){
	if(depth == cctv.size()){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(room[i][j] == 0) cnt++;
			}
		}
		ret = min(cnt,ret);
		return;
	}

	for(int dir = 0; dir < 4; dir++){
		vector<pair<int,int>> _change = extendCCTV(depth, dir);
		DFS(depth + 1);
		for(auto b : _change) room[b.first][b.second] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> room[i][j];
			if(room[i][j] > 0 && room[i][j] < 6) cctv.push_back({i,j});
		}
	}

	DFS(0);
	cout << ret << '\n';

	return 0;
}