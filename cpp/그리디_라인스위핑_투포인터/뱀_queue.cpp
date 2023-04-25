#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;
int ret,a,b, n, k, l,idx,snake_size, board[101][101], visited[101][101];
vector<pair<int, char>> directions;
queue<pair<int,int>> q;

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

void move(int y, int x, int d, int cnt){
	// 이동 횟수
	ret++;

	//뱀의 위치를 관리하는 queue
	q.push({y,x});
	visited[y][x] = 1;
	
	// test();

	if(cnt == directions[idx].first){
		char direction = directions[idx].second;
		if(direction == 'D'){ // 오른쪽 회전
			d = (d + 1) % 4;
		}else if(direction == 'L'){ // 왼쪽 회전
			d = (d + 3) % 4;
		}
		idx++;
	}
	//방향 확인 후 이동
	int ny = y + dy[d];
	int nx = x + dx[d];

	//벽이거나 몸에 부딪히면 종료
	if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] == 1) return;

	// 사과면 뱀 사이즈 늘리기
	if(board[ny][nx] == 1){
		snake_size++;
		board[ny][nx] = 0;
	}

	// 사과를 먹은만큼만 뱀의 사이즈를 유지
	if(q.size() > snake_size){
		tie(a,b) = q.front(); q.pop();
		visited[a][b] = 0;
	}
	move(ny,nx,d,cnt+1);
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
		directions.push_back({time, direction});
	}
	
	move(0,0,0,0);
	cout << ret << '\n';
	return 0;
}