#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
using namespace std;

int N;
double s;
priority_queue<double> pq;
vector<double> ret;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> s;

		pq.push(s);
		if(pq.size() == 8){
			pq.pop();
		}
	}

	while(pq.size()){
		ret.push_back(pq.top()); pq.pop();
	}
	reverse(ret.begin(), ret.end());
	for(double s : ret){
		printf("%.3lf\n", s);
	}
	return 0;
}