#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int n, a[202], dp[202];

void input(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		// printf("\n %d\n", a[i]);
	}
}

void solve(){
	int mx = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = 1;
		for(int j = 1; j < i; j++){
			if(a[i] > a[j] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
				mx = max(mx,dp[i]);
			}
		}
	}

	int ans = n - mx;
	printf("%d\n", ans);
	// for(int i = 0; i <= n; i++){
	// 	printf("%d", dp[i]);
	// }
}

int main(){
	input();
	// 긴 부분수열 찾아서 옮기면?
	solve();
}