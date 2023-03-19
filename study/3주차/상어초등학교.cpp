#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

struct STUDENT{
	int me;
	int like[4];
	int y, x;
};

int N;
int board[20][20];
STUDENT st[400];

int getPoint(int y, int x, int s){
	int point = 0;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if(board[ny][nx] == 0) point++;
		else{
			for(int f = 0; f < 4; f++){
				if(board[ny][nx] == st[s].like[f]) point += 10;
			}
		}
	}
	return point;
}

void setStudent(int y, int x, int s){
	st[s].y = y, st[s].x = x;
	board[y][x] = st[s].me;
}

int calcPoint(int s){
	int point = 0;
	int y = st[s].y;
	int x = st[s].x;

	for(int d = 0; d < 4; d++){
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		for(int f = 0; f < 4; f++){
			if(board[ny][nx] == st[s].like[f]){
				if(point == 0){
					point++;
				}else{
					point *= 10;
				}
			}
		}
	}

	return point;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N * N; i++){
		cin >> st[i].me >> st[i].like[0] >> st[i].like[1] >> st[i].like[2] >> st[i].like[3];
	}

	for(int i = 0; i < N * N; i++){
		int candiy = -1, candix = -1, point = -1;
		for(int y = 0; y < N; y++){
			for(int x = 0; x < N; x++){
				if(board[y][x] == 0){
					int curPoint = getPoint(y,x,i);
					if(point < curPoint){
						candiy = y, candix = x, point = curPoint;
					}
				}
			}
		}
		setStudent(candiy, candix, i);
	}

	int ret = 0;
	for(int i = 0; i < N * N; i++){
		ret += calcPoint(i);
	}
	cout << ret << "\n";
	return 0;
}