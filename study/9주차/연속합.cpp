#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
typedef long long ll;

using namespace std;

int n, ret = INT_MIN;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += v[i];
		ret = max(ret,sum);
		if(sum < 0) sum = 0;
	}
	cout << ret << '\n';
}