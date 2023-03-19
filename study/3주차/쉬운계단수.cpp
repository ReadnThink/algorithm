#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int N;
int dp[9999999];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	dp[1] = 9;

	for(int i = 2; i <= N; i++){
		dp[i] = (dp[i - 1] + 9 - 1) % 1000000000;
	}
	cout << dp[N];
}