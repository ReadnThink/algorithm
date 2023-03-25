#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <map>
using namespace std;

int N, ret, arr[10004];
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

void Soultion(){
	for(pair<int,int> x : v){
		pq.push(x.second);
		if(pq.size() > x.first){
			cout << "pq top = " << pq.top() << '\n';
			pq.pop();
		}
	}

	while(pq.size()){
		ret += pq.top(); pq.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b; cin >> a >> b;
		v.push_back({b,a});
	}
	sort(v.begin(), v.end());
	Soultion();
	cout << ret << '\n';
	return 0;
}