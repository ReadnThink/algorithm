#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 11;
int N,ret = INT_MAX,comp[MAX], a[MAX];
bool visited[MAX];
vector<int> adj[MAX];


void input(){
	cin >> N;

	for(int i = 1; i <= N; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= N; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			int tmp;
			cin >> tmp;
			adj[i].push_back(tmp);
			adj[tmp].push_back(i);
		}
	}
}

pair<int, int> dfs(int here, int value){
    visited[here] = 1; 
    pair<int, int> ret = {1, a[here]}; 
    for(int there : adj[here]){
        if(comp[there] != value) continue; 
        if(visited[there]) continue; 
        pair<int, int> _temp = dfs(there, value); 
        ret.first += _temp.first; 
        ret.second += _temp.second;  
    }
    return ret; 
}  

void solution(){
	for(int i = 1; i < (1 << N) - 1; i++){
		memset(comp, 0, sizeof(comp));
		memset(visited, 0, sizeof(visited));
		int idx1 = -1; int idx2 = -1;
		for(int j = 0; j < N; j++){
			if(i & (1 << j)){
				comp[j + 1] = 1;
				idx1 = j + 1;
			}else {
				idx2 = j + 1;
			}
		}
		pair<int,int> comp1 = dfs(idx1, 1);
		pair<int,int> comp2 = dfs(idx2, 0);
		if(comp1.first + comp2.first == N) ret = min(ret, abs(comp1.second - comp2.second));
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	solution();

	cout << (ret == INT_MAX ? -1 : ret) << "\n";
}