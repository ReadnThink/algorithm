#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;

char board[1004][1004];
int n,m, sx,sy, ret, y, x;
const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};
const int INF = 987654321;
int fire_check[1004][1004], person_check[1004][1004];
queue<pair<int,int>> q;

void input(){
	cin >> n >> m;
	// 불의 시간 최댓값으로 초기화
	fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
			if(board[i][j] == 'F'){
				fire_check[i][j] = 1; // 불 발생 시간 초기화
				q.push({i,j}); // 불을 동시에퍼트리기 위해 queue에 넣기
			}else if(board[i][j] == 'J'){
				sy = i; sx = j; //사람 위치 -> 불이 전부 퍼지고 돌아야 함
			}
		}
	}
}

void print(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", fire_check[i][j]);
		}
		printf("\n");
	}
}

void bfs_fire(){
	// 불 퍼트리기 -> 초기에 불 위치가 전부 들어가 있음
	while(q.size()){
		tie(y,x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(fire_check[ny][nx] != INF|| board[ny][nx] == '#') continue;
			fire_check[ny][nx] = fire_check[y][x] + 1;
			q.push({ny,nx});
		}
	}
}

void bfs(){
	bfs_fire();
	// print();
	q.push({sy,sx});
	person_check[sy][sx] = 1;
	while(q.size()){
		tie(y,x) = q.front(); q.pop();

		if(y == 0 || x == 0 || y == n-1|| x == m-1){
			ret = person_check[y][x];
			break;
		}

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(person_check[ny][nx] || board[ny][nx] == '#') continue;
			if(person_check[y][x] + 1 >= fire_check[ny][nx]) continue;
			person_check[ny][nx] = person_check[y][x] + 1;
			q.push({ny,nx});
		}
	}
}

int main(){
	input();
	bfs();
	if(ret != 0) printf("%d\n",ret);
	else printf("IMPOSSIBLE\n");
	// print();

}