#include <bits/stdc++.h>
using namespace std;

int n, w, l, trucks[1001];
queue<int> bridge;
deque<int> truck;
void input(){
	cin >> n >> w >> l;
	for(int i = 0; i < n; i++){
		cin >> trucks[i];
		truck.push_back(trucks[i]);
	}
}

void solve(){
	for(int i = 0; i < w; i++) bridge.push(0); // q에 미리 0,0을 넣어두기
	int weight = 0;
	int clock = 0;

	while(bridge.size()){
		int out = bridge.front(); bridge.pop();
		weight -= out;
		clock++;
		if(truck.size()){
			if(l >= weight + truck[0]){
				int left = truck.front(); truck.pop_front();
				weight += left;
				bridge.push(left);;
			}else{
				bridge.push(0);
			}
		}
		
	}
	cout << clock << '\n';
}

int main(){
	input();
	solve();
}

void print(){
	cout << '\n';
}