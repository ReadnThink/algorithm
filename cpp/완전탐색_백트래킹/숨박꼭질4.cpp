#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define prev viectory

using namespace std;
const int max_n = 200000;
int N,K, res, prev[max_n], visited[max_n];
queue<int> q;
vector<int> v;

void bfs(int now){
	q.push(now);
	visited[now] = 1;
	while(q.size()){
		now = q.front(); q.pop();

		if(now == K) break;

		for(int next : {now * 2, now + 1, now - 1}){

			if(next < 0 || next > max_n) continue;
			if(visited[next]) continue; 
			visited[next] = visited[now] + 1;
			prev[next] = now;
			q.push(next);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	bfs(N);
	for(int i = K; i != N; i = prev[i]){
		v.push_back(i);
	}
	v.push_back(N);
	reverse(v.begin(),v.end());

	cout << visited[K] - 1<< "\n";
	for(auto i : v) cout << i << " ";
}