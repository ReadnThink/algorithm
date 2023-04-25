#include <iostream>
#include <vector>
using namespace std;

const int V = 10;
vector<int> adj[V];
bool visited[V];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	adj[0].push_back(1); adj[0].push_back(2); adj[0].push_back(3);

	adj[1].push_back(0); adj[1].push_back(2);

	adj[2].push_back(0); adj[2].push_back(1);

	adj[3].push_back(0);

	for(int i = 0; i < 4; i++) {
		cout << i << " :: ";
		for(auto cur : adj[i]){
			cout << cur << " ";
		} 
	cout << "\n";
	}
}