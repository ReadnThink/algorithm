#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M,res, a[10][10], visited[10][10];
vector<pair<int,int>> virusList;
vector<pair<int,int>> emptyList;
vector<vector<int>> buildWallList;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0 ,-1 };


void comb(int start, int r, vector<int> v){
	if(v.size() == r){
		buildWallList.push_back(v);
		return;
	}
	for(int i = start + 1; i < emptyList.size(); i++){
		v.push_back(i);
		comb(i, r, v);
		v.pop_back();
	}
}

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx < 0 || ny < 0 || ny >= N || nx >= M) continue;
		if(visited[ny][nx] || a[ny][nx] == 1) continue;
		visited[ny][nx] = 1;
		dfs(ny,nx);
	}
	return;
}

int cal(){
	memset(visited, 0, sizeof(visited));
	for(pair<int,int> i : virusList){
		visited[i.first][i.second] == 1;
		dfs(i.first,i.second);
	}
	int safe = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(a[i][j] == 0 && !visited[i][j]) safe++;
		}
	}
	return safe;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> a[i][j];
			if(a[i][j] == 2) virusList.push_back({i,j});
			if(a[i][j] == 0) emptyList.push_back({i,j});
		}
	}

	// for(pair<int,int> i : virusList) cout << i.first << " : " << i.second <<"\n";

	vector<int> v;
	comb(-1, 3, v);

	for(vector<int> list : buildWallList){
		for(auto i : list){
			a[emptyList[i].first][emptyList[i].second] = 1;
		}
		res = max(res,cal());
		for(auto i : list){
			a[emptyList[i].first][emptyList[i].second] = 0;
		}
	}

	cout << res << "\n";
}

