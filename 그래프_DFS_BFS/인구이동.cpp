#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>

using namespace std;

int  N,L,R,res,sum,a[54][54], visited[54][54];
vector<pair<int,int>> v;
bool isUnion;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void dfs(int y, int x){
	visited[y][x] = 1;
	v.push_back({y,x});
	sum += a[y][x];

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		int limit = abs(a[y][x] - a[ny][nx]);

		if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
		if(limit >= L && limit <= R){
			dfs(ny,nx);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;

	
	for(int i = 0; i < N; i++)	{
		for(int j = 0; j < N; j++){
			cin >> a[i][j];
		}
	}

	while(true){
		isUnion = false;
		memset(visited,0,sizeof(visited));

		for(int i = 0; i < N; i++)	{
			for(int j = 0; j < N; j++){
				if(!visited[i][j]){
					sum = 0;
					v.clear();
					dfs(i,j);
					
					if(v.size() == 1) continue;
					for(pair<int,int> p : v){
						isUnion = true;
						a[p.first][p.second] = sum / v.size();
					}
				}
			}
		}
		if(!isUnion)break;
		res++;
	}
	cout << res << "\n";
}
