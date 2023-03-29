#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <set>
using namespace std;

int people, party, knowM, ret;
vector<int> v_double_check;
vector<int> v_party[54];
set<int> s_know;

bool check(int person){
	for(auto i : s_know){
		if(i == person) return false;
	}
	return true;
}

void add(vector<int> person){
	for(auto p : person){
		s_know.insert(p);
	}
}
/**
 * 
 * 반례
 * 
 * 
input
5 4
1 5
2 1 2
2 2 3
2 3 4
2 4 5

ans
0

wrong output
2
*/
int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> people >> party;
	cin >> knowM;
	for(int i = 0; i < knowM; i++){
		int tmp; cin >> tmp;
		s_know.insert(tmp);
	}
	int num;
	for(int i = 0; i < party; i++){
		 cin >> num;

		for(int j = 0; j < num; j++){
			int tmp; cin >> tmp;
			v_party[i].push_back(tmp);
		}
	}

	//진실이 있는 파티는 모두가 진실을 알게 한다.
	for(int i = 0; i < party; i++)	{
		bool flag = true;
		for(auto p : v_party[i]){
			if(!check(p)){
				// p가 아닌 v_part[i]를 넘겨줘서 set에 추가해야함 
				add(v_party[i]);
				flag = false;
			}
		}
		if(flag) {
			v_double_check.push_back(i);
		}
	}
	// cout << "double check \n";
	// for(auto k : v_double_check) cout << k << ' ';
	// cout << '\n';
	// cout << "know \n";
	// for(auto k : v_know) cout << k << ' ';
	// cout << '\n';

	//진실을 아는 사람들을 다시 체크
	for(int i = 0; i < v_double_check.size(); i++){
		bool flag = true;
		for(auto p : v_party[v_double_check[i]]){
			if(!check(p)){
				flag = false;
				break;
			}
		}
		if(flag) ret++;
	}
	cout << ret << '\n';
}