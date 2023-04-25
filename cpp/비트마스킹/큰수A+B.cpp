#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string A,B;

string add_string(){
	int sum = 0;
	string ret;
	while(A.size() || B.size() || sum){
		if(A.size()){
			sum += A.back() - '0';
			A.pop_back();
		}
		if(B.size()){
			sum += B.back() - '0';
			B.pop_back();
		}
		ret += (sum % 10) + '0';
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	cin >> A >> B;

	cout << add_string() << '\n';
	return 0;
}