#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int n = 4;
string a[n] = {"Apple!", "Strawberry!", "Grape!", "Watermelon!"};
	/*
		집합 구하는 방법
	*/
void get_set(){

	for(int i = 0; i < (1 << n); i++){
	string ret = "";
		// cout << i << " : "; // 디버깅
		for(int j = 0; j < n; j++){

			if(i & (1 << j)){
				ret += (a[j] + " ");
			}
		}
		// cout << '\n';
		cout << ret << '\n';
	}
}

/*
	매개변수 전달하기
*/
void send_param(int num){
	string ret = "";
	for(int i = 0; i < 4; i++){
		// visited[nx] = 1
		if(num & (1 << i)) ret += a[i] + " ";
		// visited[nx] = 0
	}
	cout << ret << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	/*
		집합 구하는 방법
	*/
	// get_set();

	/*
		매개변수 전달하기
	*/
	for(int i = 1; i < n; i++){
		send_param(i | (1 << i));
	}
	return 0;
}