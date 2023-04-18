#include <iostream>
#include <vector>

using namespace std;

int n, m, a[2004], dp[2004][2004];
vector<pair<int,int>> query;

void input(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int q,w;
		scanf("%d %d", &q,&w); query.push_back({q,w});
	}
}

void print(){
	printf("\n");
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < n; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

void half_search(){ // 절반만 탐색해보기
	for(int i = 0; i < m; i++){ // m번만큼 반복
		int s = query[i].first;
		int e = query[i].second;
		int mid = (s + e) / 2;
		
		bool flag = true; // 펠린드롬 체크
		for(int j = s; j < mid; j++){
			// printf("idx = %d %d\n", j, mid);
			if(a[j] != a[e - j]) {
				flag = false; // 같지 않다면 실패
			}
		}
		if(flag) printf("1\n");
		else printf("0\n");
	}
}

void solve_dp(){
	for(int i = 1; i <= n; i++){ // 1개는 펠린드롬
		dp[i][i] = 1;
	}
	
	for(int i = 1; i <= n; i++){ // 본인과 바로앞이 같다면 펠린드롬
		if(a[i] == a[i + 1]) dp[i][i + 1] = 1;
	}
	// print();
	for(int size = 2; size <= n; size++){
		for(int i = 1; i <= n - size; i++){
			if(a[i] == a[i + size] && dp[i + 1][i + size - 1]){
				dp[i][i + size] = 1;
			}
		}
	}
	// print();
	for(int i = 0; i < m; i++){
		int from = query[i].first;
		int to = query[i].second;
		printf("%d\n", dp[from][to]);
	}
}

int main(){
	input();
	// print();

	// dp로 풀어야 한다.
	solve_dp();

	// 절반만 탐색하면 되지 않을까? -> 시간초과
	// half_search();

}