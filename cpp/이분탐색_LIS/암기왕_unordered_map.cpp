#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
typedef long long ll;

using namespace std;
int t,n, m, ret;
unordered_map<int,int> mp;

vector<int> v;
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while(t--){
		cin >> n;
		mp.clear();
		int temp;
		for(int i = 0; i < n; i++){
			cin >> temp;
			mp[temp]++;
		}

		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> temp;
			if(mp[temp]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}