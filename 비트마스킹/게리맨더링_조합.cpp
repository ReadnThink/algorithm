#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 11;
int N,ret = INT_MAX, people[MAX], test[MAX];
bool selected[MAX], visit[MAX];
vector<int> adj[MAX];


void input(){
	cin >> N;

	for(int i = 1; i <= N; i++){
		cin >> people[i];
		test[i] = i;
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

bool isConnected(vector<int> v, bool flag){
	memset(visit, false, sizeof(visit));
	queue<int> q;
	q.push(v[0]);
	visit[v[0]] = true;
	int cnt = 1;

	while(q.size()){
		int x = q.front(); q.pop();

		for(auto value : adj[x]){
			if(selected[value] != flag || visit[value]) continue;
			cnt++;
			visit[value] = true;
			q.push(value);
		}
	}
	if(v.size() == cnt) return true;
	else return false;
}

bool isOk(){
	vector<int> a;
	vector<int> b;

	for(int i = 1; i <= N; i++){
		if(selected[i])a.push_back(i);
		else b.push_back(i);
	}

	if(a.empty() || b.empty()) return false;

	if(!isConnected(a, true)) return false;
	if(!isConnected(b, false)) return false;

	return true;
}

void calc(){
	int a_sum = 0;
	int b_sum = 0;

	for(int i = 1; i <= N; i++){
		if(selected[i]) a_sum += people[i];
		else b_sum += people[i];
	}

	ret = min(ret,abs(a_sum - b_sum));
}

void dfs(int start, int depth){
	if(depth >= 1){
		if(isOk()){
			calc();
		}
		// for(int i = 1; i <= N; i++){
		// 	if(selected[i]) cout << test[i] << " ";
		// }
		// cout << "\n";
	}

	for(int i = start; i <= N; i++){
		if(selected[i]) continue;
		selected[i] = true;
		dfs(i + 1, depth + 1);
		selected[i] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	// cout << "----------------------------------------------\n\n\n\n";
	dfs(1,0);
	if(ret == INT_MAX) ret = -1;
	cout << ret << "\n";
}