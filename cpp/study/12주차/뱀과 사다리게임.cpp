#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int n, m, visited[101];
vector<pair<int,int>> up, down;
queue<int> q;
map<int, int> mp;

void input(){
	scanf("%d %d", &n, &m);
	int a, b;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a,&b);
		up.push_back({a,b});
		mp.insert({a,b});
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d", &a,&b);
		down.push_back({a,b});
		mp.insert({a,b});
	}
}

int bfs(int cur){
	q.push(cur);
	visited[cur] = 1;

	while(q.size()){ // bfs 탐색
		int cur = q.front(); q.pop();

		for(int i = 1; i <= 6; i++){ // 주사위 6가지 경위의 수 모두 탐색
			int next = cur + i;
			if(next > 100) continue;
			if(mp[next]) next = mp[next];
			if(visited[next]) {
				if(visited[next] > visited[cur] + 1){
					visited[next] = visited[cur] + 1;
					q.push(next);
				}else{
					continue;
				}	
			}
			if(!visited[next]){
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}
	return visited[100] - 1;
}

void solve(){
	printf("%d\n", bfs(1)); // 0부터 시작해서 틀림...
	// for(int i = 0; i <= 100; i++){
	// 	printf("%d ",visited[i]);
	// }
}

int main(){
	input();
	solve();
}