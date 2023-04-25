#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;
int n, ret, dp[1000001];

int dfs(int n){
	if(n == 1) return 0;
	if(dp[n]) {
		cout << dp[n] << '\n';
		return dp[n];
	}

	int result = dfs(n -1) + 1;
	cout << n << " :: " << result << '\n';
	if(n % 3 == 0) result = min(result, dfs(n / 3) + 1);
	if(n % 2 == 0) result = min(result, dfs(n / 2) + 1);
	dp[n] = result;
	return dp[n];
}

int main(){
	cin >> n;
	cout << dfs(n) << '\n';
	for(int i = 2; i <= n; i++) cout << dp[i] << ' ';
	return 0;

}