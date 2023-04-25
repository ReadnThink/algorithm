#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll n, m, ret = -1;
vector<ll> v;

bool check(ll mid){
	int sum = 0;
	for(int i = 0; i < m; i++){
		sum += v[i] / mid;
		if(v[i] % mid) sum += 1;
	}
	return sum <= n;
}

int main(){
	cin >> n >> m;
	ll tmp;
	ll lo = 1, hi = 0;
	for(int i = 0 ; i < m; i++) {
		cin >> tmp; v.push_back(tmp);
		hi = max(hi, v[i]);
	}

	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		if(check(mid)){
			hi = mid - 1;
			ret = (ret, mid);
		}else{
			lo = mid + 1;
		}
	}

	cout << ret << '\n';
}
