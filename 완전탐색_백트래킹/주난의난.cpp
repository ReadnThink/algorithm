#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N, M,target_x,target_y,start_x,start_y,cnt, visited[304][304];
string tmp;
vector<string> v_map;
queue<pair<int,int>> q;
bool is_found;
const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};

void bfs(int y, int x){
	q.push({y,x});
	visited[y][x] = 1;

	while(!is_found){
		cnt++;
		queue<pair<int,int>> tmp;
		while(q.size()){
			tie(y,x) = q.front(); q.pop();

			if(visited[target_y][target_x]) {
				is_found = true;
				break;
			}

			for(int i = 0; i < 4; i++){
				int ny = y+dy[i];
				int nx = x+dx[i];

				if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
				visited[ny][nx] = cnt;
				if(v_map[ny][nx] == '0'){
					q.push({ny, nx});
				}else{
					v_map[ny][nx] = '1';
					tmp.push({ny, nx});
				}
			}
		}
		q = tmp;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> start_y >> start_x >> target_y >> target_x;
	target_y--;
	target_x--;
	start_y--;
	start_x--;
	for(int i = 0; i < N; i++){
		cin >> tmp;
		v_map.push_back(tmp);
	}

	bfs(start_y,start_x);

	cout << visited[target_y][target_x] << "\n";
	
	cout << "\n";
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}