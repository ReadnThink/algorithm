#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int N;
string s, d = ".";
vector<string> v;
map<string,int> mp;

string split(string input, string delimiter){
	vector<string> ret;
	long long pos = 0;
	string token = "";
	pos = input.find(delimiter);
	input.erase(0,pos + delimiter.length());
	return input;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//그룹화, 정렬 - 오름차순

	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> s;
		v.push_back(split(s, d));
	}

	for(string s : v) {
		mp[s]++;
	}

	for(auto it : mp) {
		cout << (it).first << " " << (it).second << '\n';
	}
}