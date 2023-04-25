#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <stack>
using namespace std;

int n, ret = -1, dp[20];
vector<pair<int,int>> v;
int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a,b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}

	//뒤에서부터 값을 저장한다.
	for(int i = n - 1; i >= 0; i--){
		// 범위를 벗어나면
		if(v[i].first + i > n) {
			dp[i] = dp[i + 1];
			continue; 
		}

		//dp에 저장되있는 수중 max를 더해야 한다.
		dp[i] = max(v[i].second + dp[i + v[i].first], dp[i + 1]);
	}

	// for(int i = 0; i < n; i++){
	// 	cout << dp[i] << ' ';
	// } 
	// cout << '\n';
	cout << dp[0] << '\n';
	return 0;
}