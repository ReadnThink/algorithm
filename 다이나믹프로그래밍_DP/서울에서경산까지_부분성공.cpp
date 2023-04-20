#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll n, k, ret;

struct WAY{
	ll a,b,c,d;
}way[104];
vector<WAY> city;

void input(){
	scanf("%d %d", &n,&k);
	int a,b,c,d;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		city.push_back({a,b,c,d});
	}
}

void dfs(int idx, ll time, ll sum){
	if(time > k){
		return;
	}
	if(idx == n){
		ret = max(ret,sum);
		return;
	}

	dfs(idx + 1, time + city[idx].a, sum + city[idx].b);
	dfs(idx + 1, time + city[idx].c, sum + city[idx].d);
}

int main(){
	input();
	dfs(0,0,0);
	
	printf("%d", ret);
	return 0;
}