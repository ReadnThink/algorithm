#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
void print();

int v,e,start, sum, cnt, dist[30001];
vector<pair<int,int>> adj[30001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

void input(){
	cin >> v >> e >> start;

	int u,v,w;
	for(int i = 0; i < e; i++){
		cin >> u >> v >> w;
		adj[u].push_back({w,v});
	}
}

void solve(){
	fill(dist, dist + 30001, INF);
	pq.push({0, start});
	dist[start] = 0;

	while(pq.size()){
		int cur = pq.top().second;
		int cur_node = pq.top().first; 
		pq.pop();

		if(dist[cur] != cur_node) continue;
		
		for(pair<int,int> next : adj[cur]){
			int _node = next.first;
			int _value = next.second;
			if(dist[_value] > dist[cur] + _node){
				dist[_value] = dist[cur] + _node;
				pq.push({dist[_value], _value});
			}
		}
	}
	for(int i = 1; i <= v; i++){
		if(dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}

int main(){
	input();
	solve();
}

void print(){
	cout << '\n';
}