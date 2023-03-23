#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <map>

using namespace std;

int N,num;
string s;
map<int,int> mp;


void input(){
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> s; 
		if(s != "all" && s != "empty"){
			cin >> num;
		}
		if(s == "add"){
			// cout << s << " : " << num << '\n';
			mp[num] = 1;
		}
		if(s =="remove"){
			mp[num] = 0;
		}
		if(s =="check"){
			if(mp[num]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if(s =="toggle"){
			if(mp[num]) mp[num] = 0;
			else mp[num] = 1;
		}
		if(s =="all"){
			for(int i = 1; i <= 20; i++){
				mp[i] = 1;
			}
		}
		if(s == "empty"){
			mp.clear();
		}
	}
}

void test(){
}



void Solve(){
	input();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Solve();
	// test();
}