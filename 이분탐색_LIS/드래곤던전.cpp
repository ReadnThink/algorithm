#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
typedef long long ll;
using namespace std;

ll n, atk, ret;

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> atk;
	ll t,a,h, hp = 0;
	for(int i = 0; i < n; i++){
		cin >> t >> a >> h;

		if(t == 1){
			ll attck = h / atk;
			if(attck == 0) continue;
			if((h % atk) == 0) attck--;
			hp += (a * attck);
			ret = max(ret,hp);
			
		}else{
			hp -= h;
			if(hp < 0) hp = 0;
			atk += a;
		}
	}
	cout << ret + 1 << '\n';
}
