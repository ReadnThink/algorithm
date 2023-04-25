#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
const int mx = 99;
using namespace std;

int n, dp[100001];
vector<int> hp;
vector<int> fun;

int main(){
	cin >> n;
	int cur_hp = mx;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp; hp.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		cin >> temp; fun.push_back(temp);
	}

	for(int i = 0; i < n; i++){
		cout << "start point = "<< mx - hp[i] << "\nend point = " << hp[i] << '\n';
		for(int j = mx; j >= hp[i]; j--){
			dp[j] = max(dp[j], dp[j - hp[i]] + fun[i]);
		}

		for(int j = 0; j <= mx; j++){
			cout << dp[j] << ' ';
		}
		cout << '\n';
	}
	cout << dp[mx] << '\n';
	return 0;
}