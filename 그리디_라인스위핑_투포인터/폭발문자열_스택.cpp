#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <map>
using namespace std;

stack<char> stk;
string str, boom, ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> str >> boom;
	char last_ch = boom[boom.size() - 1];

	for(int i = 0; i < str.size(); i++){
		stk.push(str[i]);
		
		if(stk.size() >= boom.size() && stk.top() == last_ch){
			string check;
			for(int j = 0; j < boom.size(); j++){
				//stk 뽑아서 reverse 후 확인하기
				check += stk.top();stk.pop();
			}
			reverse(check.begin(), check.end());

			if(check != boom){
				for(int j = 0; j < boom.size(); j++){
					//stk 뽑아서 reverse 후 확인하기
					stk.push(check[i]);
				}
			}
		}
	}

	if(stk.size() == 0) cout << "FRULA" << '\n';
	else {
		while(stk.size()){
			ret += stk.top(); stk.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret << "\n";
	}
	
	return 0;
}