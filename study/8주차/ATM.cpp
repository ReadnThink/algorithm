#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

int n, ret, psum[1001];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
	cin >> n;
	int tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());


	for(int i = 1; i <= n; i++)	{
		psum[i] = psum[i - 1] + v[i - 1];
	}
	
	for(int i = 1; i <= n; i++)	{
		ret += psum[i];
	}
	cout << ret << '\n';
	return 0;
}