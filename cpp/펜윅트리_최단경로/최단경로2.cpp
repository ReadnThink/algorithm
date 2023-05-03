#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int v, e, k, dist[50001], visited[50001];
vector<pair<int,int>> adj[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

void input(){
	cin >> v >> e;
	int u,v,w;
	for(int i = 0; i < e; i++){
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({w,w});
	}
	fill(dist,dist+50001,INF);
}

void solve(){
	pq.push({0, 1});
	dist[1] = 0;

	while(pq.size()){
		int cur_node = pq.top().second;
		pq.pop();
		if(visited[cur_node]) continue;
		visited[cur_node] = 1;

		for(auto p : adj[cur_node]){
			int next = p.first; // 다음 노드
			int value = p.second; // 가중치
			if(dist[next] > dist[cur_node] + value){
				dist[next] = dist[cur_node] + value;
				pq.push({dist[next], next});
			}
		}
	}

}

int main(){
	input();
	solve();
	
	for(int i = 1; i <=v; i++){
		// if(!visited[i]) cout << "INF\n";
		// else cout << dist[i] << '\n';
		cout << dist[i] << ' ';
	}
	cout << dist[v] << ' ';
	// cout << '\n';
}