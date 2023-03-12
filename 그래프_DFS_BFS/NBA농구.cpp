#include <iostream>
#include <vector>
#define prev victorory
using namespace std;

int N;
int team, A, B, asum, bsum;
string s, prev;

string print(int a){
	string d = "00" + to_string(a / 60);
	string e = "00" + to_string(a % 60);
	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int changeToInt(string a){
	return atoi(a.substr(0,2).c_str()) * 60 + atoi(a.substr(3,2).c_str());
}

void go(int &sum, string s){
	sum += changeToInt(s) - changeToInt(prev);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> team >> s; 
		if(A > B) go(asum, s);
		else if(B > A) go(bsum, s);
		team == 1 ? A++ : B++;
		prev = s;
		// cout << "------------------------\n";
		// cout << "asum = " << asum << "\n";
		// cout << "bsum = " << bsum << "\n";
	}
	//prev와 48이 종료시점이기때문에 빼주면 마지막 시간이 나온다.
	if(A > B)go(asum, "48:00");
	else if(B > A) go(bsum, "48:00");
	// cout << "************************\n";
	// cout << "asum = " << asum << "\n";
	// cout << "bsum = " << bsum << "\n";
	
	cout << print(asum) << "\n";
	cout << print(bsum) << "\n";
}