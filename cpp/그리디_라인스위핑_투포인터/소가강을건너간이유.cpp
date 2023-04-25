#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <map>
using namespace std;

int N,a,b,ret;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<pair<int,int>> v;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(), v.end());
	int time = v[0].first + v[0].second;
	for(int i = 1; i < v.size(); i++){
		time = max(time, v[i].first);
		time += v[i].second;
	}
	cout << time << '\n';
	return 0;
}