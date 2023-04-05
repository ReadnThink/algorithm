#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <stack>
using namespace std;

int n, ret;
stack<int> stk;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
	cin >> n;
	int tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp != 0) stk.push(tmp);
		else stk.pop();
	}

	while(stk.size()){
		ret += stk.top();
		stk.pop();
	}
	cout << ret << '\n';
	return 0;
}