#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <map>
using namespace std;

int N,a,b,ret;
vector<pair<int,int>> v;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v.push_back({b,a});
	}

	sort(v.begin(), v.end());
	int time = v[0].first;
	ret++;
	for(int i = 1; i < N; i++){
		if(time > v[i].second) continue;
		ret++;
		time = v[i].first;
	}
	cout << ret << '\n';
}