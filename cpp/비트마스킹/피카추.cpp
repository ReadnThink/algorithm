#include <iostream>
#include <vector>

using namespace std;

string str;

int check(int start){{
	int idx = 0;
	if(str[start] == 'p'){
		if(str[start + 1] == 'i') idx++;
	}
	else if(str[start] == 'k'){
		if(str[start + 1] == 'a') idx++;
	}else if(str[start] == 'c'){
		if(str[start + 1] == 'h' && str[start + 2] == 'u') idx+=2;
	}
	return idx;
}

}

int main(){
	cin >> str;

	for(int i = 0; i < str.length(); i++){
		if(check(i)){
			i += check(i);
		}else{
			cout << "NO" <<'\n';
			exit(0);
		}
	}
	cout << "YES" <<'\n';
}