#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

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

void dfs(int idx, int p, int f, int t, int v, int sum){
	// cnt++;
	if(idx == N + 1){
		// cout << sum << "\n";
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
		return;
	}
	
	vec.push_back(idx);
	dfs(idx + 1, p + fd[idx].protine, f + fd[idx].fet, t + fd[idx].tan, v + fd[idx].vitamin, sum + fd[idx].price);
	vec.pop_back();
	dfs(idx + 1, p, f, t, v, sum);

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> min_p >> min_f >> min_tan >> min_v;

	for(int i = 1; i <= N; i++){
		cin >> fd[i].protine >> fd[i].fet >> fd[i].tan >> fd[i].vitamin >> fd[i].price; 
	}

	dfs(1,0,0,0,0,0);
	if(ret == INT_MAX) ret = -1;
	cout << ret << "\n";
	sort(ret_vec.begin(), ret_vec.end());
	for(auto i : ret_vec) cout << i << " ";
	cout << "\n";

	//디버깅
	// cout << cnt << "\n";
	return 0;
}