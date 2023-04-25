#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;


int n,m,k,ret = INT_MAX ,a[101][101], temp[101][101], visited[7];
vector<int> v;


struct Idx{
	int r;
	int c;
	int s;
};
vector<Idx> turn;
void test(){
	cout << "\n-----------------\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << temp[i][j] << ' ';
		}
		cout << '\n';
	}
}

void rotate(int r, int c, int S){
	//배열 돌리기
	
	// printf("%d : %d : %d : %d\n", r-S,c-S,r+S,c+S);

	for(int s = 1; s <= S; s++){
		//위
        int upTmp = temp[r-s][c+s];
        for(int y = c+s; y > c-s; y--) {
            temp[r-s][y] = temp[r-s][y-1];
        }
        //오른쪽
        int rightTmp = temp[r+s][c+s];
        for(int x = r+s; x > r-s; x--) {
            temp[x][c+s] = temp[x-1][c+s];
        }
        temp[r-s+1][c+s] = upTmp;
        //아래
        int leftTmp = temp[r+s][c-s];
        for(int y = c-s; y < c+s; y++) {
            temp[r+s][y] = temp[r+s][y+1];
        }
        temp[r+s][c+s-1] = rightTmp;
        //왼쪽
        for(int x = r-s; x < r+s; x++) {
            temp[x][c-s] = temp[x+1][c-s];
        }
        temp[r+s-1][c-s] = leftTmp;
	}
	// test();
}

void Solve(){
	memcpy(temp, a, sizeof(a));
	// memset(temp,0, sizeof(temp));
	
	for(int i = 0; i < v.size(); i++){
		Idx t = turn[v[i]];
		// temp를 회전
		rotate(t.r - 1, t.c - 1, t.s);
	}

	//계산하기
	for(int i = 0; i < n; i++){
		int cnt = 0;

		for(int j = 0; j < m; j++){
			cnt += temp[i][j];
		}
		ret = min(ret, cnt);
	}

}

void perm(int depth){
	if(depth == k){
		Solve();
	}

	for(int i = 0; i < k; i++){
		if(visited[i]) continue;
		visited[i]=1;
		v.push_back(i);
		perm(depth + 1);
		visited[i]=0;
		v.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	int a,b,c;
	for(int i = 0; i < k; i++){
		cin >> a >> b >> c;
		turn.push_back({a, b, c});
	}
	perm(0);
	cout << ret << '\n';
}