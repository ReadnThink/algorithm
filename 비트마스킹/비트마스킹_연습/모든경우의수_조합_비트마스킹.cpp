#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;
int N,M,ret,visited[100];

void Input(){
	cin >> N;
}

void bitMask(){
	for(int i = 1; i < (1 << N); i++){
		for(int j = 0; j <= i; j++){
			if(i & (1 << j)){
				cout << j + 1 << ' ';
			}
		}
		cout << "\n";

		if(i == (1 << N) - 1) cout << i << '\n';
	}

}

void DFS(int idx, int cnt){
	ret++;
	for(int i = 1; i <= N; i++){
		if(visited[i]){
			cout << i << ' ';
		}
	}
	cout << '\n';

	for(int i = idx; i <= N; i++){
		if(visited[i]) continue;
		visited[i] = true;
		DFS(i, cnt+1);
		visited[i] = false;
	}
}

void Solve(){
	Input();
	bitMask();
	cout << "------------------------\n";
	DFS(1,0);
	cout << ret << '\n';
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Solve();
}