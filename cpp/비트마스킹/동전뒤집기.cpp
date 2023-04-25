#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int N, a[44], ret = INT_MAX;
string s;

void go(int here){
	if(here == N + 1){
		int sum = 0;
		for(int i = 1; i <= (1 << (N - 1)); i *= 2){
			int cnt = 0;
			for(int j = 1; j <= N; j++){
				if(a[j] & i)cnt++;
			}
			sum += min(cnt, N - cnt);
		}
		ret = min(ret,sum);
		return;
	}

	a[here] = ~a[here];
	go(here + 1);
	a[here] = ~a[here];
	go(here + 1);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> s;
		int value = 1;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == 'T')a[i] |= value;
			value *= 2;
		}
	}
	go(1);
	cout << ret << '\n';
}