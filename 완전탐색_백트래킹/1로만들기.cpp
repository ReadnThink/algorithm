#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, ret, dp[1000001];
void input(){
	scanf("%d", &n);
	ret = 987654321;
}

void print(){
	printf("\n");
	printf("\n");
}

int dfs(int x){
	if(x == 1)	return 0;
	int &ret = dp[x];
	if(ret) return dp[x];
	ret = 987654321;

	if(!(x % 3)) ret = min(ret, dfs(x/3) + 1);
	if(!(x % 2)) ret = min(ret, dfs(x/2) + 1);
	ret = min(ret, dfs(x - 1) + 1);
	return dp[x];
}

int main(){
	input();
	int ans = dfs(n);
	// for(int i = 1; i <= n; i++) printf("%d ", dp[i]);
	// printf("\n");
	printf("%d\n", ans);
}