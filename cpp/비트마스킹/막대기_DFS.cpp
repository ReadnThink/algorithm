#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <numeric>

using namespace std;
int N, ret, words[51];
vector<int> v;
void Input(){
	cin >> N;
}
void DFS(int stick){
	if(N == 0){
		cout << ret << '\n';
		exit(0);
	}	
	if(N == stick){
		cout << 1 << '\n';
		exit(0);
	}
	if(stick > N){
		stick /= 2;
		//반쪽 막대가 더 길면
		if(stick > N){
			DFS(stick);
		}else{// 아니면
			N -= stick;
			ret++;
			DFS(stick);
		}
	}

}

void Solve(){
	Input();
	DFS(64);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Solve();
}