#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <queue>

using namespace std;
int N;
long long ret;
vector<long long> km,price;

// void test_print(){
// 	for(int i = N; i < N + 10; i++){
// 		for(int j = M; j < M + 10; j++){
// 			cout << visited[i][j] << ' ';
// 		}
// 		cout << '\n';
// 	}
// }

void Input(){
	cin >> N;
	long long tmp;
	for(int i = 0; i < N - 1; i++){
		cin >> tmp;
		km.push_back(tmp);
	}
	for(int i = 0; i < N; i++){
		cin >> tmp;
		price.push_back(tmp);
	}
}


void Solution(){
	long long min_cost = price[0];

	ret += price[0] * km[0];

	for(int i = 1; i < km.size(); i++){

		if(price[i] >= min_cost){
			ret += min_cost * km[i];
		}else if(price[i] < min_cost){
			min_cost = price[i];
			ret += price[i] * km[i];
		}
	}
}

void Solve(){
	Input();
	Solution();
	// Test_print();
	cout << ret << '\n';
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Solve();
}