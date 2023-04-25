#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
typedef long long ll;

using namespace std;

int n,k, ret, dp[100001];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
	}
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = v[i]; j <= k; j++){
			dp[j] += dp[j - v[i]];
		}
		for(int j = 0; j <= k; j++){
			cout << dp[j] << ' ';
		}
		cout << '\n';
	}
	ret = dp[k];
	cout << ret << '\n';
}