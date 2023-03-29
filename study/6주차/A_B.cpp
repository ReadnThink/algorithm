#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long n, m, ret = INT_MAX;

void dfs(long long a, long long cnt){
	if(a > m) return;
	if(a == m){
		ret = min(ret, cnt);
	}
	dfs(a * 2, cnt + 1);
	dfs(a * 10 + 1, cnt + 1);
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;
	dfs(n, 1);
	if(ret == INT_MAX) ret = -1;
	cout << ret << '\n';
}