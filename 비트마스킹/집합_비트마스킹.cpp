#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <bitset>

using namespace std;

int N,num,ret;
string s;


void input(){
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> s;
		if(s != "all" && s != "empty")	cin >> num;

		if(s == "add"){
			ret |= (1 << num);
			// cout << "to add Binary ->" << num << "  |= : " << bitset<8>(ret) << '\n';
		}
		if(s == "remove"){
			ret &= ~(1 << num);
			// cout << "to add Binary ->" << num << "  &= : " << bitset<8>(ret) << '\n';
		}
		if(s == "check"){
			printf("%d\n", (ret&(1 << num)) ==0? 0: 1);
		}
		if(s == "toggle"){
			ret ^= (1 << num);
			// cout << "to add Binary ->" << num << "  ^= : " << bitset<8>(ret) << '\n';
		}
		if(s == "all"){
			ret = (1 << 21) - 1;
			// cout << "to add Binary ->" << num << "  all = : " << bitset<22>(ret) << '\n';
		}
		if(s == "empty"){
			ret = 0;
			// cout << "to add Binary ->" << num << "  empty = : " << bitset<8>(ret) << '\n';
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