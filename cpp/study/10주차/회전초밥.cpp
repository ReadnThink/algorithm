#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

int n, d, k, c,mx,ret, dish[30001];
vector<int> v;
void input(){
	cin >> n >> d >> k >> c;

	for(int i = 0; i < n; i++){
		cin >> dish[i];
	}
}

void output(){
	// for(int i = 0; i < n; i++){
	// 	cout << dish[i] << ' ';
	// }
	// cout << '\n';

	cout << ret << '\n';
}

void solve(){
	for(int i = 0; i < n; i++){
		int visited[d + 1] = {0, };
		int eat_sushi = 1;
		visited[c] = 1;

		for(int j = i; j < i + k; j++){
			int sushi = dish[j % n];
			if(!visited[sushi]) {
				eat_sushi++;
			}
			visited[sushi]++;
		}
		mx = max(mx, eat_sushi);
	}

	ret = mx;
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	input();
	solve();
	output();
}