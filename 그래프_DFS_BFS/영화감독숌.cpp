#include <iostream>
#include <vector>
#include <string>

#define prev victorory

using namespace std;

int N, ret, cnt;
string s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int i = 665;
	for(;;i++){
		if(to_string(i).find("666") != string::npos) N--;
		if(N == 0) break;
	}
	cout << i << "\n";
}