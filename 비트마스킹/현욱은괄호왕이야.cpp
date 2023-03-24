#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;

int N, ret;
string str;
stack<int> stk;

void Solution_arr(){
	int d[200004];
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '(')stk.push(i);
		else if(stk.size()){
			d[i] = d[stk.top()] = 1;   
			stk.pop();
		}
	}
	int cnt = 0;
	for(int i = 0; i < str.size(); i++){
		if(d[i]){
			cnt++;
		}else cnt = 0;
		ret = max(ret,cnt);
	}
}
void Solution_stk(){
	stk.push(-1);
	for(int i = 0; i < N; i++){
		if(str[i] == '(') stk.push(i);
		if(str[i] == ')'){
			stk.pop();
			if(!stk.empty()){
				ret = max(ret, i - stk.top());
			} else{
				stk.push(i);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> str;
	// Solution_arr();
	Solution_stk();
	cout << ret << '\n';
	return 0;
}