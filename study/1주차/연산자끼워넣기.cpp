


#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
int N, a[15], visited[15], way[5];
int ret_max = -1000000001, ret_min = 1000000001;


void dfs(int depth, int sum){
	if(depth == N - 1){
		ret_max = max(ret_max, sum);
		ret_min = min(ret_min, sum);
		return;
	}

	for(int i = 0; i < 4; i++){
		if(way[i] > 0){
			way[i]--;
			if(i == 0) dfs(depth + 1, sum + a[depth + 1]);
			else if (i == 1) dfs(depth + 1, sum - a[depth + 1]);
			else if (i == 2) dfs(depth + 1, sum * a[depth + 1]);
			else dfs(depth + 1, sum / a[depth + 1]);
			way[i]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	for(int i = 0; i < 4; i++){
		cin >> way[i];
	}

	dfs(0, a[0]);
	cout << ret_max << "\n";
	cout << ret_min << "\n";
}