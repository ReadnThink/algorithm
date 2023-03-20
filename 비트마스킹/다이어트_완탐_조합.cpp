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
int N,cnt,ret = INT_MAX, min_p, min_f, min_tan, min_v, min_price;
vector<int> ret_vec;
vector<vector<int>> v_combList;

bool check(int p, int f, int t, int v){
	if(p >= min_p && f >= min_f && t >= min_tan && v >= min_v) return true;
	return false;
}

void comb(int start, vector<int> v){
	v_combList.push_back(v);

	for(int i = start + 1; i <= N; i++){
		v.push_back(i);
		comb(i,v);
		v.pop_back();
	}
}

void dfs(vector<int> v){
	cnt++;
	int p = 0;	int f = 0;	int t = 0;	int vm = 0;	int sum = 0;
	for(auto i : v){
		p += fd[i].protine; 
		f += fd[i].fet;
		t += fd[i].tan;
		vm += fd[i].vitamin;
		sum += fd[i].price;
	}

	if(check(p,f,t,vm)){
		if(ret > sum){
			ret_vec = v;
			ret = sum;
		}else if(ret == sum && ret_vec > v){
			ret_vec = v;
		}
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> min_p >> min_f >> min_tan >> min_v;

	for(int i = 1; i <= N; i++){
		cin >> fd[i].protine >> fd[i].fet >> fd[i].tan >> fd[i].vitamin >> fd[i].price; 
	}

	vector<int> comb_v;
	comb(0,comb_v);

	for(vector<int> v : v_combList){
		// for(auto i : v) cout << i << " ";
		// cout << "\n";
		dfs(v);
	}

	if(ret == INT_MAX) ret = -1;

	sort(ret_vec.begin(), ret_vec.end());
	cout << ret << "\n";
	for(auto i : ret_vec) cout << i << " ";
	cout << "\n";

	//디버깅
	// cout << cnt << "\n";
	return 0;
}