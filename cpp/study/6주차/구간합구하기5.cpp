#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int n,m, ret, a[1025][1025], dp[1025][1025];

void test_print(){
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + a[i][j];
		}
	}
	
	int x1, y1, x2, y2;
	for(int i = 0; i < m; i++){
		cin >> x1 >> y1 >> x2 >>y2;
		ret = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
		cout << ret << '\n';
	}
}