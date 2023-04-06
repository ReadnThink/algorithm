#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
typedef long long ll;

using namespace std;
ll x,y,percent, ret = -1;
bool check(ll mid){
	ll temp = ((y + mid) * 100 / (x + mid));
	if(temp > percent) return true;
	return false;
}

int main(){
	//승률 승리 / 총경기 * 100 double??
	cin >> x >> y;

	percent = y * 100 / x;
	ll lo = 1, hi = 1000000001;
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