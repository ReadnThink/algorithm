#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
typedef long long ll;
using namespace std;

int k, len;
vector<int> nums;
vector<char> op;
set<vector<int>, greater<vector<int>>> s;
void printV(){
	for(auto i : nums) cout << i << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin >> k;
	char temp;
	for(int i = 0; i < k; i++){
		cin >> temp;
		op.push_back(temp);
	}
	for(int i = 0; i < 10; i++)	nums.push_back(i);

	do{
		bool flag = true;
		char oper = ' ';
		for(int i = 0; i < k; i++){
			if(op[i] == '<'){
				if(nums[i] > nums[i + 1]) flag = false;
			}else if(op[i] == '>'){
				if(nums[i] < nums[i + 1]) flag = false;
			}
		}
		if(flag){
			vector<int> temp;
			for(int i = 0; i <= k; i++){
				temp.push_back(nums[i]);
			}
			s.insert(temp);
		}
	}while(next_permutation(nums.begin(), nums.end()));

	int idx = 0;
	for(auto v : s){
		if(idx == 0 || idx == s.size() - 1){
			for(auto i : v) cout << i;
			cout << '\n';
		}
		idx++;
	}
	return 0;
}