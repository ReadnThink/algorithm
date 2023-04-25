#include <iostream>
#include <vector>
#include <cstring>

typedef long long ll;
using namespace std;

int n,ret;
vector<int> hp,joy;

void input(){
	scanf("%d", &n);
	int temp;
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		hp.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		joy.push_back(temp);
	}
}

void solve(int depth, int h, int sum){
	if(h >= 100){
		return;
	}
	if(depth == n) {
		ret = max(ret, sum);
		return;
	}
	//인사 하거나 안하거나
	solve(depth + 1, h + hp[depth], sum + joy[depth]);
	solve(depth + 1, h, sum);
}

int main(){
	input();
	solve(0,0,0);
	printf("%d\n", ret);
	return 0;
}