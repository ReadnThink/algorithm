#include <iostream>
#include <vector>
using namespace std;

int N,ret = -2100000000;
string s;
vector<int> nums;
vector<char> op;

int culc(char ch, int a, int b){
	if(ch == '+') return a + b;
	if(ch == '-') return a - b;
	if(ch == '*') return a * b;
}

void get_result(int depth, int sum){
	if(depth == op.size()){
		ret = max(ret,sum);
		return;
	}
	get_result(depth + 1, culc(op[depth], sum, nums[depth + 1]));
	if(depth + 2 <= op.size()){
		get_result(depth + 2, culc(op[depth], sum, culc(op[depth + 1], nums[depth + 1], nums[depth + 2])));
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> s;

	for(int i = 0; i < N; i++){
		if(i % 2 == 0) nums.push_back(s[i] - '0');
		else op.push_back(s[i]);
	}

	get_result(0,nums[0]);
	cout << ret << "\n";
}