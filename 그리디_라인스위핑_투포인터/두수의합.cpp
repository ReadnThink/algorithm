#include <iostream>
#include <algorithm>
using namespace std;

int N,X, a[100004], ret;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	cin >> X;
	sort(a, a + N);
	int l = 0, r = N -1;
	while(l < r){
		if(a[l] + a[r] == X) ret++, r--;
		else if(a[l] + a[r] > X) r--;
		else l++;
	}
	cout << ret << '\n';
}