#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
typedef long long ll;

using namespace std;

int n,m,k, ret, visited[1004], parents[1004];
vector<int> adj[1001], plan;

int Find(int x){
	if(parents[x] == x) return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y){
	int a = Find(x);
	int b = Find(y);
	if(a < b) parents[b] = a;
	else parents[a] = b;
}

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 1; i <= 1004; i++){
		parents[i] = i;
	}

	int temp;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> temp;
			if(temp) {
				Union(i, j);
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		cin >> temp; plan.push_back(temp);
	}

	int same = Find(plan[0]);
	bool flag = 1;
	for(auto i : plan){
		if(same != Find(i)){
			flag = false;
		}
	}
	if(flag) cout << "YES" << '\n';
	else cout << "NO\n";
}