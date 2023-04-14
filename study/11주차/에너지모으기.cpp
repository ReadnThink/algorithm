#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

int n, ret;
vector<int> v;

void printv(){
	for(auto i : v) cout << i << ' ';
	cout << '\n';
}

void dfs(int sum){
	// cout << "sum = " << sum << '\n';
	if(v.size() == 2){
		// cout << " sum = "<< sum << '\n';
		ret = max(ret, sum);
		return;
	}

	for(int i = 1; i < v.size() - 1; i++){
		int add = v[i - 1] * v[i + 1];
		cout << add << '\n';
		int temp = v[i];
		// printv();
		v.erase(v.begin() + i);
		// printv();
		dfs(sum + add);
		v.insert(v.begin() + i, temp);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
	}
	// cout << "start \n";
	dfs(0);
	cout << ret << '\n';
	return 0;
}