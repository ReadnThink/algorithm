#include <iostream>
#include <vector>
#include <string>

#define prev victory

using namespace std;
int N, team, A, B, asum, bsum, sum;
string time, prev;

string makeIntToString(int num){
	string min = "00" + to_string(num / 60);
	string sec = "00" + to_string(num % 60);
	return min.substr(min.length() - 2) + ":" + sec.substr(sec.length() - 2);
}

int makeToInt(string s){
	int min = atoi(s.substr(0,2).c_str()) * 60;
	int sec = atoi(s.substr(3,2).c_str());
	// cout << min << ":"<< sec << "\n";
	return min + sec;
}

int go(string a, string b){
	return makeToInt(a) - makeToInt(b);
}




int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	// makeToInt("2:13");
	for(int i = 0; i < N; i++){
		// cout << i << "for---------------------\n";

		cin >> team >> time;
		if(A > B) asum += go(time, prev);
		if(A < B) bsum += go(time, prev);

		if(team == 1) A++;
		else B++;

		// cout << "asum = " << asum << "\n";
		// cout << "bsum = " << bsum << "\n";

		prev = time;
	}
			// cout << "end---------------------\n";
	if(A > B) asum += go("48:00", time);
	if(A < B) bsum += go("48:00", time);

	// cout << asum << "\n";
	// cout << bsum << "\n";

	cout << makeIntToString(asum) << "\n";
	cout << makeIntToString(bsum) << "\n";
}