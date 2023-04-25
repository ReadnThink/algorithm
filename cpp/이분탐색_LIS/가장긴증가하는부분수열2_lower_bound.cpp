#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <float.h>
#include <cmath>
#include <cstring>

using namespace std;
int n,ret, a[1004], dp[1004];

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		dp[i] = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	sort(dp, dp + n);
	// for(int i = 0; i < n; i++){
	// 	cout << dp[i] << ' ';
	// }
	
	cout << dp[n - 1] << '\n';
	return 0;
}