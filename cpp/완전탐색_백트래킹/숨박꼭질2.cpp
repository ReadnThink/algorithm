#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N,K, res, way,cnt[100004], visited[100004];
queue<int> q;
void bfs(int now){
	q.push(now);
	visited[now] = 1;
	cnt[now] = 1;
	while(q.size()){
		now = q.front(); q.pop();
		// cout << now << " : " << visited[now] << "\n";
		for(int next : {now - 1, now + 1, now * 2}){

			if(next < 0 || next > 100000) continue;
			if(visited[next]) {
				if(visited[now] + 1 == visited[next]) 
					cnt[next] += cnt[now];
			} else {
				visited[next] = visited[now] + 1;
				cnt[next] += cnt[now];
				q.push(next);
			}
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	bfs(N);
	cout << visited[K] - 1<< "\n";
	cout << cnt[K] << "\n";
}