#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;
using namespace std;
map<int,int> mp;

int n, m, ret;

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		mp[temp]++;
	}
	for(int i = 0; i < m; i++){
		cin >> temp;
		mp[temp]++;
	}

	for(auto i : mp){
		if(i.second == 1) ret++;
	}
	cout << ret << '\n';
}
