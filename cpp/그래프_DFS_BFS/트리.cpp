#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N,R, root;
vector<int> adj[55];

int DFS(int here){
	int ret = 0;
	int child = 0;
	for(int there : adj[here]){
		if(there == R) continue;
		ret += DFS(there);
		child++;
	}
	if(child == 0) return 1;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for(int i = 0; i < N; i++){
		int tmp; cin >> tmp;
		if(tmp == -1) root = i;
		else adj[tmp].push_back(i);
	}
	cin >> R;
	if(R == root) {
		cout << 0 << "\n"; 
		return 0;
	}

	cout << DFS(root) << "\n";
	return 0;

}


