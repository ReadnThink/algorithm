#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>

typedef long long ll;

using namespace std;
int t,n,m,k,a,b,ret, arr[50][50], visited[50][50];
vector<int> v;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void dfs(int y, int x){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx])continue;
		if(arr[ny][nx] == 0) continue;
		dfs(ny,nx);
	}
}

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> t;

	while(t--){
		cin >> m >> n >> k;
		memset(visited,0,sizeof(visited));
		memset(arr,0,sizeof(arr));
		ret = 0;
		for(int i = 0; i < k; i++){
			cin >> b >> a;
			arr[a][b] = 1;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!visited[i][j] && arr[i][j] != 0){
					dfs(i,j);
					ret++;
				}
			}
		}
		v.push_back(ret);
	}
	for(auto i : v) cout << i << '\n';
}