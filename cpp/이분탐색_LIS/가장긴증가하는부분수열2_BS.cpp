#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <float.h>
#include <cmath>
#include <cstring>

using namespace std;
int n,ret, a[1000004];

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n;
	int temp;
	int idx = 0;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(i == 0 || temp > v[idx]){
			v.push_back(temp);
			if(i != 0) idx++;
		}else {
			int l = 0;
			int r = v.size() - 1;
			while(l <= r){
				int mid = (l + r) / 2;
				if(v[mid] >= temp)r = mid - 1;
				else l = mid + 1;
			}
			v[l] = temp;
		}
	}
	cout << v.size() << '\n';

	return 0;
}