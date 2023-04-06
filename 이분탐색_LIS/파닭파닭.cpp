#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
typedef long long ll;

using namespace std;
ll s, c,mx, ret;
vector<ll> v;

bool check(ll mid){
	ll cnt = 0;
	for(int i = 0; i < s; i++){
		cnt += v[i] / mid;
	}
	return cnt >= c;
}

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> s >> c;
	int temp;
	for(int i = 0; i < s; i++){
		cin >> temp;
		mx += temp;
		v.push_back(temp);
	}
	ll lo = 1, hi = LONG_MAX;
	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		if(check(mid)){
			lo = mid + 1;
			ret = mid;
		}else{
			hi = mid - 1;
		}
	}

	cout << mx - ret * c << '\n';
}