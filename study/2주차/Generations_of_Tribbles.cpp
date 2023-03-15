#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>

using namespace std;
int T, N;
long long dp[74];
int f(int n){
	if(n < 2) return dp[1];
	if(n == 2) return dp[2];
	if(n == 3) return dp[3];
	if(dp[n]) return dp[n];
	return dp[n] = f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	

	for(int i = 0; i < T; i++){
		cin >> N;
		// cout << f(N) << "\n";
		for(int j = 4; j <= N; j++){
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3] + dp[j - 4];
		}
		cout << dp[N] << "\n";
	}
}
