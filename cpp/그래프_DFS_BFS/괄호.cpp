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
	for(char c : s){
		if(c == '(')stk.push(c);
		else{
			if(!stk.empty())stk.pop();
			else return false;
		}
	}
	return stk.empty();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s;
		if(check(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}