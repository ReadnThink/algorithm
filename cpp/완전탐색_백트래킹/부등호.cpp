#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using namespace std;
int K,ret;
long long ret_min = 999999999, ret_max = -999999999;
int nums[10];
string s;
vector<char> v;
vector<int> tmp, v_max, v_min, v_per;
bool check(char ch, int a, int b){
	if(ch == '<') {
		if(a < b) {
			return true;
		}
	}
	else if(ch == '>') {
		if(a > b) {
			return true;
		}
	}
	return false;
}

void change(long long sum){
	if(ret_max <= sum){
		v_max = tmp;
	}
	if(ret_min > sum){
		v_min = tmp;
	}
	ret_max = max(ret_max,sum);
	ret_min = min(ret_min,sum);
}

// void dfs(int depth, long long sum){
// 	if(depth == K + 1){
// 		bool flag = true;
// 		for(int i = 0; i < tmp.size() - 1; i++){
// 			if(!check(v[i], tmp[i], tmp[i + 1])) flag = false;
// 		}
// 		if(flag){
// 			ret++;
// 			change(sum);
// 		}

		
// 	}
// 	//완전탐색
// 	for(int i = 0; i <= 9; i++){
// 		if(!nums[i]){
// 			tmp.push_back(i);
// 			nums[i]++;
// 			dfs(depth + 1, sum + i);
// 			tmp.pop_back();
// 			nums[i]--;
// 		}
		
// 	}
// }

void n_per(){
	do{	
		// for(int i = 0; i < K + 1; i++){
		// 	cout << v_per[i] << " ";
		// }
		// cout << "\n";


		bool flag = true;
		for(int i = 0; i < K + 1; i++){
			if(!check(v[i], v_per[i], v_per[i + 1])) flag = false;
		}

		if(flag){
			ret++;
			change((long long)accumulate(v_per.begin(), v_per.end(), 0LL));
		}

	}while(next_permutation(v_per.begin(), v_per.end()));
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K;

	for(int i = 0; i < K; i++){
		char tmp; cin >> tmp;
		v.push_back(tmp);
	}

	// dfs(0,0);
	for(int i = 0; i <= 9; i++) v_per.push_back(i);
	n_per();
	for(auto i : v_max) cout << i << "";
	cout << "\n";
	for(auto i : v_min) cout << i << "";
}
