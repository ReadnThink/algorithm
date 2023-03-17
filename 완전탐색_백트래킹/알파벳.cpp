#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};
string s;
int N, M, ret;
vector<string> board;
map<char,int> mp;

void dfs(int y, int x, int cnt){
	ret = max(ret,cnt);

	for(int i = 0; i < 4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];

		if(ny < 0 || nx < 0 || ny >= N || nx >= M ) continue;
		if(mp[board[ny][nx]]) continue;
		mp[board[ny][nx]]++;
		dfs(ny,nx, cnt + 1);
		mp[board[ny][nx]]--;
	}	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < N; i++){
		cin >> s;
		board.push_back(s);
	}
	mp[board[0][0]]++;
	dfs(0,0,1);
	cout << ret << "\n";
}