#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string s;

bool isIncludeFive(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	else return false;
}

bool pwCheck(string s){

	int five_alpha = 0, rest_alpha = 0;
	char prev = s[0];
	bool include_five = 0;
	bool flag = 0;
	for(int i = 0; i < s.size(); i++){
		char c = s[i];
		if(isIncludeFive(c)) {
			five_alpha++;
			rest_alpha = 0;
			include_five = 1;
		} else{
			rest_alpha++;
			five_alpha = 0;
		}
		if(five_alpha == 3 || rest_alpha == 3) flag = 1;
		if(i > 0 && (c == prev) && (c != 'e' && c != 'o')) flag = 1;
		prev = c;
	}
	if(include_five == 0) flag = 1;

	if(flag) return false;
	else return true;
}

int main(){
	//같은글자 연속 x -> ee, oo는 가능
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(true){
		cin >> s;
		if(s == "end") {
			break;
		}

		if(pwCheck(s)) 
			cout << "<" << s << ">" <<  " is acceptable.\n";
		else 
			cout << "<" << s << ">" << " is not acceptable.\n";
	}

}