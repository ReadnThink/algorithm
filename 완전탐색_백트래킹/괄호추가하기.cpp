#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, res;
string s;
vector<int> num_list;
vector<char> op_list;

int oper(char a, int b, int c){
	if(a == '+') return b + c;
	if(a == '-') return b - c;
	if(a == '*') return b * c;
}

void dfs(int here, int num){
	cout << here << " : " << num << "\n";
	if(here == num_list.size() - 1){
		res = max(res, num);
		return;
	}

	dfs(here + 1, oper(op_list[here], num, num_list[here + 1]));
	cout << "COME BACK----------------\n"<< here << " : " << num << "\n";
	if(here + 2 <= num_list.size() - 1){
		cout << "IN TEMP----------------------------\n"<< here << " : " << num << "\n";
		int temp = oper(op_list[here + 1], num_list[here + 1], num_list[here + 2]);
		cout << "-------------GET TEMP-----------------\n"<< here << " : " << num << " // temp = " << temp << "\n";
		dfs(here + 2, oper(op_list[here], num, temp));
	}
	cout << "\n\nfinish--- ==  "<< here << " : " << num << "\n\n";
	return;
}

/* 
9 
3+8*7-9*2
*/

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> s;

	for(int i = 0; i < N; i++){
		if(i % 2 == 0) num_list.push_back(s[i] - '0');
		else op_list.push_back(s[i]);
	}
	cout << "num_list SIZE = " << num_list.size() << "\n";
	dfs(0, num_list[0]);
	cout << res << "\n";
}