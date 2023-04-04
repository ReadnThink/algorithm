#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;
int n,m,t,x,d,k,circle[50][50], ret, visited[50][50],y;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
bool flag;
void _rotate(int pick, int dir, int k){
	vector<int> v;
	for(int i = 0; i < m; i++)v.push_back(circle[pick][i]);

	if(dir == 1) rotate(v.begin(), v.begin() + k, v.end());
	else rotate(v.begin(), v.begin() + m - k, v.end());

	for(int i = 0; i < m; i++) circle[pick][i] = v[i];
}

void dfs(int y, int x){
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = (x + dx[i] + m) % m;
		if(ny < 0 || ny >= n) continue;
		if(visited[ny][nx]) continue;
		if(circle[y][x] == circle[ny][nx]){
			visited[y][x] = visited[ny][nx] = 1;
			flag = 0;
			dfs(ny,nx);
		}
	}
}

bool findAdj(){
	flag = 1;
	memset(visited,0,sizeof(visited));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(circle[i][j] == 0) continue;
			if(visited[i][j])continue;
			dfs(i,j);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j]) circle[i][j] = 0;
		}
	}
	return flag;
}

void setAverage(){
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(circle[i][j] == 0)continue;
			sum += circle[i][j];
			cnt++;
		}
	}
	double av = (double)sum / (double)cnt;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(circle[i][j] == 0) continue;
			if((double)circle[i][j] > av) circle[i][j]--;
			else if((double)circle[i][j] < av) circle[i][j]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> t;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> circle[i][j];
		}
	}

	for(int i = 0; i < t; i++){
		cin >> x >> d >> k;
		for(int j = x - 1; j < n; j += x){
			_rotate(j,d,k);
		}
		if(findAdj())setAverage();
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(circle[i][j]) ret += circle[i][j];
		}
	}
	cout << ret << '\n';
	return 0;
}