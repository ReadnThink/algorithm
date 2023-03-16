#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

int  N,M,res,visited[54][54];
string s[54];
queue<pair<int,int>> q;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void bfs(int y, int x){
	visited[y][x] = 1;
	q.push({y,x});

	while(q.size()){
		tie(y,x) = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
			if(s[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			res = max(visited[ny][nx] , res);
			q.push({ny,nx});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for(int i = 0; i < N; i++)	cin >> s[i];
	
	for(int i = 0; i < N; i++)	{
		for(int j = 0; j < M; j++){
			if(s[i][j] == 'L'){
				// cout << i << " : " << j << "------------------\n";
				memset(visited,0,sizeof(visited));
				bfs(i,j);
			}
		}
	}

	cout << res - 1 << "\n";
}
