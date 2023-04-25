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

	for(auto s : str){
		ret += s;
		if(ret.size() >= boom.size() && ret.substr(ret.size() - boom.size(), boom.size()) == boom){
			ret.erase(ret.end() - boom.size(), ret.end());
		}
	}
	if(!ret.size())cout << "FRULA" << '\n';
	else cout << ret << '\n';

	return 0;
}