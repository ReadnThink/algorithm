#include <bits/stdc++.h>
using namespace std;
int n,m,w_sum,ret, psum_s[3000004];
string s;
void input(){
	cin >> n >> m;
	
	cin >> s;
	for(int j = 0; j < s.size(); j++){
		w_sum += s[j] - '0';
	}
	cin >> s;
	for(int j = 0; j < s.size(); j++){
		psum_s[j + 1] = psum_s[j] + s[j] - '0';
	}
}

void solve(){
	// 누적합 구하기 -> 순열을 덧셈으로 구할 예정
	for(int i = n; i <= m; i++){
		int sum = psum_s[i] - psum_s[i - n];
		// cout << sum << '\n';
		if(w_sum == sum) ret++;
	}
	cout << ret << '\n';
}

int main(){
	input();
	solve();
}