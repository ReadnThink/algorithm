#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, l, ret;
vector<pair<int,int>> v;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> l;

	for(int i =0; i < n; i++){
		int a,b; cin >> a >> b;
		v.push_back({a,b});
	}

	sort(v.begin(), v.end());
	int start = 0;
	for(int i = 0; i < v.size(); i++){
		if(start < v[i].first) start = v[i].first;

		while(start < v[i].second){
			start += l;
			ret++;
		}
	}
	cout << ret << '\n';
}