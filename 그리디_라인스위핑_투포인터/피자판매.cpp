#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;
const int max_n = 1001;
int want, n, m, temp, cnt;
int a[max_n], b[max_n], ret, psum_a[max_n * 2], psum_b[max_n];
map<int,int> aCnt, bCnt;

void make(int n, int psum[], map<int,int> &_map){
	for(int interval = 1; interval <= n; interval++){
		for(int start = interval; start <= n + interval - 1; start++){
			int sum = psum[start] - psum[start - interval];
			_map[sum]++;
			if(interval == n) break;
		}
	}
	return;
}

void solution(){
	for(int i = 1; i < want; i++){
		ret += aCnt[want - 1] * bCnt[i];
	}
	ret += aCnt[want];
	ret += bCnt[want];

}

int main(){
	ios_base::sync_with_stdio(NULL); cout.tie(NULL);cin.tie(NULL);
	cin >> want >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		psum_a[i] = psum_a[i - 1] + a[i];
	}
	for(int i = n + 1; i <= 2 * n; i++){
		psum_a[i] = psum_a[i - 1] + a[i - n];
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
		psum_b[i] = psum_b[i - 1] + b[i];
	}
	for(int i = m + 1; i <= 2 * m; i++){
		psum_b[i] = psum_b[i - 1] + b[i - m];
	}

	make(n,psum_a, aCnt);
	make(m,psum_b, bCnt);

	solution();

	cout << ret << '\n';
	return 0;
}