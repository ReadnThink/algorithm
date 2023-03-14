#include <iostream>
#include <vector>

using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void dfs(int depth){
	// if(visited[depth]) return;
	visited[depth] = 1;
	cout << depth << "\n";
	for(auto i : adj[depth]){
		if(!visited[i]) dfs(i);
	}
	cout << depth << "로부터 시작한 한수가 종료되었습니다.\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[4].push_back(2);
	adj[2].push_back(5);

	dfs(1);
}