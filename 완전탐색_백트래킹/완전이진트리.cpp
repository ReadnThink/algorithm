#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

int K;
vector<int> v, ret[14];


void divide_tree(int s, int e, int level){
	if(s > e) return;
	if(s == e){
		ret[level].push_back(v[s]);
		return;
	}
	int mid = (s + e) / 2;
	ret[level].push_back(v[mid]);
	divide_tree(s, mid - 1, level + 1);
	divide_tree(mid + 1, e, level + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	int _end = (int)pow(2, K) - 1;
	for(int i = 0; i < _end; i++){
		int tmp; cin >>tmp;
		v.push_back(tmp);
	}

	divide_tree(0, _end, 1);

	for(int i = 1; i <= K; i++){
		for(auto j : ret[i]){
			cout << j << " ";
		}
		cout << "\n";
	}
}
