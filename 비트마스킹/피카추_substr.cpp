#include <iostream>
#include <vector>

using namespace std;

string str;

int main(){
	cin >> str;

	bool flag = true;
	for(int i = 0; i < str.length(); i++){
		if(str.substr(i,2) == "pi" || str.substr(i,2) == "ka") i++;
		else if(str.substr(i,3) == "chu") i+=2;
		else flag = false;
	}
	if(flag) cout << "YES" <<'\n';
	else cout << "NO" <<'\n';
}