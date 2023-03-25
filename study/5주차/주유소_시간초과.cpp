#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <queue>

using namespace std;
int N,min_price = INT_MAX,ret;
vector<int> km,price;

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
	int tmp;
	for(int i = 0; i < N - 1; i++){
		cin >> tmp;
		km.push_back(tmp);
	}
	for(int i = 0; i < N; i++){
		cin >> tmp;
		if(i != N - 1)	min_price = min(min_price,tmp);
		price.push_back(tmp);
	}
}


void Solution(){
	for(int i = 0; i < N; i++){
		if(price[i] == min_price){
			// 풀충전
			for(int j = i; j < km.size(); j++){
				ret += price[i] * km[j];
			}
			cout << ret << '\n';
			//종료
			exit(0);
		}else{
			// 최소비용 충전
			for(int j = i; j < price.size(); j++){
				if(price[i] > price[j]) break;
				if(price[i] <= price[j]){
					ret += price[i] * km[j];
				}
				i = j - 1;
			}
			// ret += price[i] * km[i];
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