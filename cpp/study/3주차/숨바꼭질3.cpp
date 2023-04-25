#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
const int max_n = 100004;
int N, K,res = max_n + 5, visited[max_n];
deque<int> q;

void bfs(int now){
	q.push_back(now);
	visited[now] = 1;

	while(q.size()){
		now = q.front(); q.pop_front();

		if(now == K) {
			res = visited[now];
			return;
		}

		for(int next : {now+1,now-1,now * 2}){
			if(next < 0 || next > 100000) continue;
			if(visited[next]) continue; 
			
			if(next == now * 2){
				visited[next] = visited[now];
				q.push_front(next);
			}else {
				visited[next] = visited[now] + 1;
				q.push_back(next);
			}
			
		}

	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	if(N == K) {
		cout << 0 << "\n";
		exit(0);
	}
	bfs(N);
	cout << res - 1 << "\n";

}