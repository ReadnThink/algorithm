#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int t, n, m, ret;
vector<int> a,b;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		int temp;
		ret = 0; a.clear(); b.clear();
		for(int i = 0; i < n; i++){cin >> temp; a.push_back(temp);}
		for(int i = 0; i < m; i++){cin >> temp; b.push_back(temp);}
		sort(b.begin(), b.end());

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i] <= b[j]) break;
				if(a[i] > b[j]) ret++;
			}
		}
		cout << ret << '\n';
	}

}
