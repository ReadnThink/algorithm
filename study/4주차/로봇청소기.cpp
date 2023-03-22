#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
int N,M,s_x,s_y,ret, dt, visited[54][54], board[54][54];

struct ROBOT{
	 int y, x, dir;
};
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
ROBOT robot;

void input(){
	cin >> N >> M;
	cin >> robot.y >> robot.x >> robot.dir;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}
}

void test_print(){
	cout << "\n\n\n";
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();


	queue<ROBOT> q;
	q.push(robot);
	while(q.size()){
		ROBOT cur = q.front(); q.pop();
		if(board[cur.y][cur.x] == 0){
			++ret;
			board[cur.y][cur.x] = ret;
		}
		for(int i = 0; i < 4; i++){
			ROBOT next;
			next.dir = (cur.dir + 3 - i) % 4;
			next.y = cur.y + dy[next.dir];
			next.x = cur.x + dx[next.dir];

			if(next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] != 0) continue;
			q.push(next);
			break;
		}
		if(q.empty()){
			ROBOT next;
			next.dir = cur.dir;
			next.y = cur.y + dy[(next.dir + 2) % 4];
			next.x = cur.x + dx[(next.dir + 2) % 4];

			if(next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || board[next.y][next.x] == 1) break;
			cout << "return !!!  = " << next.y << " : " << next.x << '\n' ;
			q.push(next);
		}
	}

	test_print();


	cout << ret << "\n";
}