#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct FOOD{
	int protine, fet, tan, vitamin, price;
};

FOOD fd[20];
int N,ret = INT_MAX, min_p, min_f, min_tan, min_v, min_price, visited[20];
vector<int> vec, ret_vec;

bool check(int p, int f, int t, int v){
	if(p >= min_p && f >= min_f && t >= min_tan && v >= min_v) return true;
	return false;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> min_p >> min_f >> min_tan >> min_v;

	for(int i = 0; i < N; i++){
		cin >> fd[i].protine >> fd[i].fet >> fd[i].tan >> fd[i].vitamin >> fd[i].price; 
	}

	for(int i = 1; i < (1 << N); i++){
		int p = 0;	int f = 0;	int t = 0;	int v = 0;	int sum = 0;
		vector<int> vec;
		for(int j = 0; j < N; j++){
			if(i & (1 << j)){
				vec.push_back(j + 1);
				p += fd[j].protine; 
				f += fd[j].fet;
				t += fd[j].tan;
				v += fd[j].vitamin;
				sum += fd[j].price;
			}
		}
		if(check(p,f,t,v)){
			if(ret > sum){
				ret = sum;
				ret_vec = vec;
			}else if (ret == sum && ret_vec > vec){
				ret_vec = vec;
			}
		}
	}

	if(ret == INT_MAX) ret = -1;
	sort(ret_vec.begin(),ret_vec.end());
	cout << ret << "\n";
	for(auto i : ret_vec) cout << i << " ";
	cout << "\n";

}