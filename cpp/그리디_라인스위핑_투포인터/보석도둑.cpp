#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;

ll N,M,V,K,C,ret;
vector<pair<ll,ll>> tres;
vector<ll> bag;
priority_queue<ll, ll> pq;

void test_print(){
	cout << "\n in tres \n";
	for(auto i : tres){
		cout << i.first << " : " << i.second << '\n';
	}

	cout << "\n\n in bag \n";

	for(auto i : bag){
		cout << i << '\n';
	}
}

void Solution(){
	int idx = 0;
	for(int i = 0; i < K; i++){
		while(idx < N && bag[i] >= tres[idx].first){
			pq.push(tres[idx].second);
			idx++;
		} 
		if(pq.size()){
			ret += pq.top(); pq.pop();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for(int i = 0; i < N; i++){
		cin >> M >> V;
		tres.push_back({M,V});
	}
	for(int i = 0; i < K; i++){
		cin >> C;
		bag.push_back(C);
	}

	sort(tres.begin(), tres.end());
	sort(bag.begin(), bag.end());

	// test_print();

	Solution();
	cout << ret << '\n';
}