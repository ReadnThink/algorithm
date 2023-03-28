#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, table[20][20], ret = INT_MAX;
int team1[10], team2[10];
int pick[20];

void test_print(){
	for(int i = 0; i < n; i++){
		if(pick[i]) cout << i << ' ';
	}
	cout << '\n';
}

void calc(){
	int team1_size = 0, team2_size = 0;
	for(int i = 0; i < n; i++){
		if(pick[i] == 0) team1[team1_size++] = i;
		else team2[team2_size++] = i;
	}

	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n/2; i++){
		for(int j = i + 1; j < n/2; j++){
			sum1 += table[team1[i]][team1[j]] + table[team1[j]][team1[i]];
			sum2 += table[team2[i]][team2[j]] + table[team2[j]][team2[i]];
		}
	}
	if(ret > abs(sum1 - sum2)) ret = abs(sum1 - sum2);
}


void dfs(int cur, int pick_count){
	if(pick_count == n /2){
		test_print();
		calc();
		return;
	}

	for(int i = cur; i < n; i++){
		pick[i] = 1;
		dfs(i + 1, pick_count + 1);
		pick[i] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> table[i][j];
		}
	}
	//n개중에서 m을 뽑아야하기 때문에 dfs 호출
	dfs(0,0);
	cout << ret << '\n';
}