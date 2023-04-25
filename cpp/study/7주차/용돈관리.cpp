#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n,m,k,ret, money;
vector<int> v;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> k;
		ret += k;
		v.push_back(k);
	}
	ret /= 5;
	cout << ret << '\n';
}