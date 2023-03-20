#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/**
 * 실패 이유 : 순열이기때문에 시간초과가 납니다.
 * -> 조합으로 해결해야합
*/

struct FOOD{
	int protine;
	int fet;
	int tan;
	int vitamin;
	int price;
};

FOOD fd[20];
int N,cnt,ret = INT_MAX, min_p, min_f, min_tan, min_v, min_price, visited[20];
vector<int> vec, ret_vec;
bool check(int p, int f, int t, int v){
	if(p >= min_p && f >= min_f && t >= min_tan && v >= min_v) return true;
	return false;
}

void dfs(int p, int f, int t, int v, int sum){
	// cout << sum << "\n";
	// cnt++;
	if(check(p,f,t,v)){
		// cout << "check!------------------------\n";
		if(ret > sum){
			ret_vec = vec;
			ret = sum;
		}else if(ret == sum && ret_vec > vec){
			ret_vec = vec;
		}
		return;
	}

	for(int i = 1; i <= N; i++){
		if(!visited[i]){
			visited[i] = 1;
			vec.push_back(i);
			dfs(p + fd[i].protine, f + fd[i].fet, t + fd[i].tan, v + fd[i].vitamin, sum + fd[i].price);
			vec.pop_back();
			visited[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> min_p >> min_f >> min_tan >> min_v;

	for(int i = 1; i <= N; i++){
		cin >> fd[i].protine >> fd[i].fet >> fd[i].tan >> fd[i].vitamin >> fd[i].price; 
	}

	dfs(0,0,0,0,0);
	cout << ret << "\n";
	for(auto i : ret_vec) cout << i << " ";
	cout << "\n";

	//디버깅
	// cout << cnt << "\n";
	return 0;
}