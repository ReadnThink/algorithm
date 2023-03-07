#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n,m,startx,starty,endx,endy,ret ,a[104][104];
int visited[104][104];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};



void bfs(int y, int x){
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y,x});
	while(q.size()){
		tie(y, x) = q.front(); q.pop(); 
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue; 
            if(visited[ny][nx]) continue; 
            visited[ny][nx] = visited[y][x] + 1; 
            q.push({ny, nx}); 
		}
	}

}

// 5 5
// 0 0
// 4 4
// 1 0 1 0 1
// 1 1 1 0 1
// 0 0 1 1 1
// 0 0 1 1 1
// 0 0 1 1 1


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	cin >> startx >> starty;
	cin >> endx >> endy;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	bfs(starty, startx);
	cout << "정답은 "<< visited[endy][endx] << "\n";
	// 최단거리 디버깅 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        	cout << visited[i][j] << ' '; 
        }
        cout << '\n';
    } 
    return 0;
}