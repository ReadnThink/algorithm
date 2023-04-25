#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

typedef long long ll;
using namespace std;

ll t,n,m,ret, psum_A[2002], psum_B[2002];
vector<int> A,B;
void input(){
	scanf("%d", &t);
	scanf("%d", &n);
	int temp;
	// A입력
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		A.push_back(temp);
	}
	

	//B입력
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &temp);
		B.push_back(temp);
	}

	//정렬한 이유 -> 정렬하면 일렬로 뽑을 수 있을거 같다??
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for(int i = 1; i <= n; i++){
		psum_A[i] = psum_A[i - 1] + A[i];
	}
	for(int i = n + 1; i <= n * 2; i++){
		psum_A[i] = psum_A[i - 1] + A[i - n];
	}

	for(int i = 1; i <= m; i++){
		psum_B[i] = psum_B[i - 1] + B[i];
	}
	for(int i = m + 1; i <= m * 2; i++){
		psum_B[i] = psum_B[i - 1] + B[i - n];
	}
}

void solve(){

}

int main(){
	input();
	solve();
	printf("%d\n", ret);
	return 0;
}