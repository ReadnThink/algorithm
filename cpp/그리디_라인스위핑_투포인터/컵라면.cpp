#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <map>
using namespace std;

int N,a,b,ret;
vector<pair<int,int>> v_pair;
priority_queue<int, vector<int>, greater<int>> pq;

void Solve(){
	for(auto i : v_pair){
		pq.push(i.second);
		cout << pq.size() << " :  i first = " << i.first << '\n';
		if(pq.size() > i.first){
			
			cout << pq.top() << '\n';
			pq.pop();
		}
	}

	cout << "finish------------\n";
	while(pq.size()){
		cout << pq.top() << '\n';
		ret += pq.top(); pq.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a >> b;
		v_pair.push_back({a,b});
	}

	sort(v_pair.begin(), v_pair.end());
	Solve();
	cout << ret << '\n';
	return 0;
}