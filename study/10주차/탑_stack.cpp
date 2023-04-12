#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int n,ret,k;
stack<pair<int,int>> stk;
// 숫자보다 작을경우 계속 pop을 한다.
void input(){
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> k;

		while(stk.size()){
			if(stk.top().second > k){
				cout << stk.top().first << ' ';
				break;
			}
			stk.pop();
		}
		if(stk.empty()) cout << 0 << ' ';
		stk.push({i,k});
	}
}
int main(){
	input();
}