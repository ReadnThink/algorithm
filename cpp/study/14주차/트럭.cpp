#include <bits/stdc++.h>
using namespace std;
int n, w, l, ret, temp;
vector<int> t;
queue<int> q;
void input(){
	cin >> n >> w >> l;
	for(int i = 0; i < n; i++){
		cin >> temp;
		t.push_back(temp);
	}
}

void solve(){
	int cur_weight = 0; // 무게 합
	for(int i = 0; i < n; i++) {
		while(true){
			if(q.size() == w){
				cur_weight -= q.front();
				q.pop();
			}
			if(t[i] + cur_weight <= l) break;
			q.push(0); // 트럭이 이동하게 하기 위해
			ret++;
		}
		q.push(t[i]);
		cur_weight += t[i];
		ret++;
	}
	cout << ret + w << '\n';
}

int main(){
	input();
	solve();
}