#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;

int n,m;
char board[1001][1001];
int visited[1001][1001];
vector<pair<int,int>> s,f;
queue<pair<int,int>> q;

const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};

void input(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];

			if(board[i][j] == 'J') s.push_back({i,j});
			if(board[i][j] == 'F') f.push_back({i,j});
		}
	}
}
void print(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}
void bfs(int y, int x){
	q.push({y,x});
	visited[y][x] = 1;

	while(q.size()){
		tie(y,x) = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(nx < 0 || ny < 0 || ny >= n || nx >= m)  continue;
			if(board[ny][nx] == 'J' || board[ny][nx] == '#') continue;
			if(visited[ny][nx]){
				if(visited[ny][nx] <= visited[y][x] + 1) continue;
			}
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny,nx});
		}
	}

}

void bfs_s(int y, int x){
	q.push({y,x});
	visited[y][x] = 1;

	while(q.size()){
		tie(y,x) = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(nx < 0 || ny < 0 || ny >= n || nx >= m) {
				printf("%d\n", visited[y][x]);
				exit(0);
			}
			if(board[ny][nx] == 'F' || board[ny][nx] == '#') continue;
			if(visited[ny][nx]){
				if(visited[ny][nx] <= visited[y][x] + 1) continue;
			}
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny,nx});
		}
	}

}

void solve(){
	for(auto i : f){
		bfs(i.first,i.second);
	}
	bfs_s(s[0].first,s[0].second);
}
int main(){
	input();
	solve();
	printf("IMPOSSIBLE\n");
	// print();

}