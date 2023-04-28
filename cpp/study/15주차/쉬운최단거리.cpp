#include <bits/stdc++.h>

using namespace std;

int n,m,sx,sy,y,x, board[1004][1004], visited[1004][1004];

const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 2) {
                sy = i; sx = j;
            }
        }
    }
}

void bfs(){
    queue<pair<int,int>> q;
    q.push({sy,sx});
    visited[sy][sx] = 0;

    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            if(board[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);    
    input();
    bfs();
    // cout << "====================\n";
    visited[sy][sx] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == sy && j == sx) cout << 0 << ' ';
            else if(board[i][j] == 0) cout << visited[i][j] << ' ';
            else if (visited[i][j] == 0) cout << -1 << ' ';
            else cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}