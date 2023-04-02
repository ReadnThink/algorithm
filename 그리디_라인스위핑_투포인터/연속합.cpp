#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <map>
#include <climits>

using namespace std;
const int max_n = 100001;
int n,ret = INT_MIN, num, sum;

int main(){
	ios_base::sync_with_stdio(NULL); cout.tie(NULL);cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		sum += num;
		if(sum < 0) sum = 0;
		ret = max(ret, sum);

	}
	cout << ret << '\n';
	return 0;
}