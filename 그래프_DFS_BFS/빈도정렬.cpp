#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, C, cnt[1004];
vector<pair<int,int>> v;
map<int,int> mp, mp_idx;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first){
		return mp_idx[a.second] < mp_idx[b.second];
	}
	return a.first > b.first;
}

int main(){
	cin >> N >> C;

	for(int i = 0; i < N; i++){
		int tmp; cin >> tmp;
		mp[tmp]++;
		if(mp_idx[tmp] == 0) mp_idx[tmp] = i + 1;
	}

	for(auto it : mp){
		v.push_back({it.second, it.first});
	}

	sort(v.begin(),v.end(), cmp);
	for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";
		}
	}
}