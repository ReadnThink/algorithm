#include <iostream>
#include <vector>
#include <string>
#include <stack>

#define prev victorory

using namespace std;

int N, ret, cnt;
string s;
vector<string> v;

bool check(string s){
	stack<char> stk;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') stk.push(s[i]);
		if(s[i] == '[') stk.push(s[i]);

		if(s[i] == ')'){
			if(stk.size() == 0 || stk.top() != '('){
				return false;
			} else{
				stk.pop();
			}
		}
		if(s[i] == ']'){
			if(stk.size() == 0 || stk.top() != '['){
				return false;
			} else{
				stk.pop();
			}
		}
	}

	return stk.empty();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(true){
		getline(cin,s);
		if(s == ".")break;

		if(check(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}