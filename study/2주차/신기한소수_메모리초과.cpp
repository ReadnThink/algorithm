#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <string>

using namespace std;
int N,n, V = 10000004;
bool prime[10000004];

bool check(int num){
	vector<int> v;
	string s = to_string(num);

	for(int i = 1; i <= n; i++){
		// cout << "for num = "<< s << "\n";
		// cout << "for N = "<< N << "\n";
		v.push_back(atoi(s.substr(0, i).c_str()));
	}
	// cout << "for N = "<< N << "\n";
	// cout << "num = "<< s << "\n";
	// cout << v.size() << "\n";
	for(int i = 0; i < v.size(); i++){
		// cout <<"vector = " << v[i] << "\n";
		if(!prime[v[i]]) {
			return false;
		}
	}

	return prime[num];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	n = N;
	
	memset(prime,1,sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for(int i = 2; i * i <= V; i++){
		for(int j = i * i; j <= V; j += i){
			prime[j] = false;
		}
	}
	check(11);
	// if(!prime[10]) cout << prime[10];

	int limit = 10;
	int start = 1;
	N--;
	while(N){
		start *= 10;
		limit *= 10;
		N--;
	}

	limit - 1;
	// cout << "-------------------\n";
	for(int i = start; i <= limit; i++){
		if(prime[i]) {
			if(check(i)){
				cout << i << "\n";
			}
		}
	}

}
