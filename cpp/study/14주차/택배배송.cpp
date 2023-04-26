#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
void print();

int v,e,start, sum, cnt, dist[50001];
vector<pair<int,int>> adj[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

void input(){
	cin >> v >> e;

	int u,v,w;
	for(int i = 0; i < e; i++){
		cin >> u >> v >> w;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
}

void solve(){
	fill(dist, dist + 50001, INF);
	pq.push({0, 1});
	dist[1] = 0;

	while(pq.size()){
		int weight = pq.top().first; 
		int cur_node = pq.top().second;
		pq.pop();

		if(dist[cur_node] != weight) continue;
		
		for(pair<int,int> next : adj[cur_node]){
			int next_weight = next.first;
			int next_node = next.second;
			
			if(dist[next_node] > dist[cur_node] + next_weight){
				dist[next_node] = dist[cur_node] + next_weight;
				pq.push({dist[next_node], next_node});
			}
		}
	}
	// for(int i = 1; i <= v; i++){
	// 	cout << dist[i] << ' ';
	// }
	// cout << '\n';
	cout << dist[v] << '\n';
}

int main(){
	input();
	solve();
}

void print(){
	cout << '\n';
}