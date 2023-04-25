#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll n, m, ret = -1, mx = -1;
vector<ll> v;

bool check(ll mid){
	if(mx > mid) return false;

	int temp = mid;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(mid - v[i] < 0){
			mid = temp;
			cnt++;
		}
		mid -= v[i];
	}
	if(mid != temp) cnt++;
	return cnt <= m;
}
int main(){
	cin >> n >> m;
	ll tmp;
	ll lo = 0, hi = 0;
	for(int i = 0 ; i < n; i++) {
		cin >> tmp; v.push_back(tmp);
		hi += v[i];
		mx = max(mx, tmp);
	}

	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		if(check(mid)){
			hi = mid - 1;
			ret = mid;
		}else{
			lo = mid + 1;
		}
	}

	cout << ret << '\n';
}
