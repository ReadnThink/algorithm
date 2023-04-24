#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

typedef long long ll;
using namespace std;
int t,v,e,visited[20001];
vector<int> adj[20001];

void input(){
	
}

void solve(){
}

void print(){
	for(int i = 1; i <= v; i++){
		cout << i << " :: ";
		for(auto value : adj[i]){
			cout << value << ' ';
		}
		cout << '\n';
	}
}

void dfs(int node){
	for(auto value : adj[node]){
		if(visited[value]) continue;
		if(visited[node] == 1) visited[value] = 2;
		else visited[value] = 1;
		dfs(value);
	}
}

bool check(){

	for(int i = 1; i <= v; i++){
		for(auto value : adj[i]){
			if(visited[i] == visited[value])return false;
		}
	}
	// for(int i = 1; i <= v; i++){
	// 	int gsize = adj[i].size();
	// 	for(int j = 0; j < gsize; j++){
	// 		int next = adj[i][j];
	// 		if(visited[i] == visited[next]){
	// 			return false;
	// 		}
	// 	}
	// }
	return true;
}

int main(){
	// input();
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &v, &e);
		
		for(int i = 0; i < e; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		// print();

		for(int i = 1; i <= v; i++)		{
			if(!visited[i]) {
				visited[i] = 1;
				dfs(i);
			}
		}


		//확인
		if(check()) cout << "YES\n";
		else cout << "NO\n";

		for(int i = 0; i <= v; i++){
			adj[i].clear();
		}
		memset(visited,0,sizeof(visited));
	}
	return 0;
}