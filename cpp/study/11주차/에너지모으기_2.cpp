#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

int n, ret;

void dfs(vector<int> v, int sum){
	if(v.size() == 2){
		ret = max(ret, sum);
		return;
	}

	for(int i = 1; i < v.size() - 1; i++){
		vector<int> tmp = v;
		tmp.erase(tmp.begin() + i);
		dfs(tmp, sum + v[i - 1] * v[i + 1]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int temp;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
	}
	dfs(v,0);
	cout << ret << '\n';
	return 0;
}