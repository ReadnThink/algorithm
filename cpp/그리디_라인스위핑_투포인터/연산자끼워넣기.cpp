#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int n, l, minRet = INT_MAX,maxRet = -2100000000,a[101],visited[101], op[11];

void DFS(int depth, int sum){
	if(depth == n - 1){
		maxRet = max(maxRet,sum);
		minRet = min(minRet,sum);
		return;
	}

	for(int i = 0; i < 4; i++){
		if(op[i]) {
			op[i]--;
			if(i == 0) DFS(depth + 1, sum + a[depth + 1]);
			else if(i == 1) DFS(depth + 1, sum - a[depth + 1]);
			else if(i == 2) DFS(depth + 1, sum * a[depth + 1]);
			else DFS(depth + 1, sum / a[depth + 1]);
			op[i]++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	DFS(0,a[0]);
	cout << maxRet << '\n';
	cout << minRet << '\n';
}