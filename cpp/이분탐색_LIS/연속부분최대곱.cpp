#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <float.h>
#include <cmath>
using namespace std;
double n,ret, a[10004];

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	double b = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] > b * a[i]) b = a[i];
		else b *= a[i];
		ret = max(b,ret);
	}
	printf("%.3f\n",ret);
	return 0;
}