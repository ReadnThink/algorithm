#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <string>

using namespace std;
int N;

bool isPrime(int number){
	for(int i = 2; i <= number /2; i++){
		if(number % i == 0) return false;
	}
	return true;
}

void dfs(int number, int idx){
	if(idx == N){
		if(isPrime(number)){
			cout << number << "\n";
		}
		return;
	}
	for(int i = 1; i <= 9; i++){
		int next_num = (number * 10) + i;
		if(i % 2 == 0) continue;
		if(isPrime(next_num)) dfs(next_num, idx + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<int> v = {2, 3, 5, 7};
	for(auto i : v){
		dfs(i, 1);
	}
	// dfs(2,1);
	// dfs(3,1);
	// dfs(5,1);
	// dfs(7,1);
}
