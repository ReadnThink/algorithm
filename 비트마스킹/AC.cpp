#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <queue>

using namespace std;
int T,N,M,ret,grid[5][5],visited[100];
string pc, arr_str;

void Input(){
	cin >> T;
	while(T--){
		cin >> pc;
		cin >> N;
		cin >> arr_str;
		
		deque<int> Dq;
		int tmp = 0;
		for(int i = 0; i < arr_str.length(); i++){
			if(arr_str[i] == '[' || arr_str[i] == ']') continue;
			if(arr_str[i] >= '0' && arr_str[i] <= '9') tmp = (tmp * 10) + arr_str[i] - '0';
			else {
				Dq.push_back(tmp);
				tmp = 0;
			}
		}
		if(tmp != 0) Dq.push_back(tmp);

		bool rev = false;
		bool er = false;
		for(char p : pc){
			if(p == 'R'){
				rev = !rev;
			}else{
				if(Dq.size()){
					if(!rev){
						Dq.pop_front();
					}else{
						Dq.pop_back();
					}
				}else{
					er = true;
					break;
				}
			}
		}
		if(rev) reverse(Dq.begin(), Dq.end());
		if(er) cout << "error" << '\n';
		else{
			cout << '[';
			for(int i = 0; i < Dq.size(); i++){
				cout << Dq[i];
				if(i != Dq.size() - 1){
					cout << ',';
				}
			}
			cout << "]\n";
		}
	}
}
void Test_print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << grid[i][j] << ' ';
		}
		cout << '\n';
	}
}


void Solve(){
	Input();
	// Test_print();
	// cout << ret << '\n';
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Solve();
}