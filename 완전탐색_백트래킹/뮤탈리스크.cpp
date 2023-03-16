#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

int N,a,b,c,res, scvs[4];
vector<int> v;
vector<int> attacks = {9,3,1};
vector<vector<int>> attackList; 
int visited[64][64][64];

struct SCV{
	int a;
	int b;
	int c;
};

queue<SCV> q;


void get_permutation(){
	do{
		attackList.push_back(attacks);
	}while(next_permutation(attacks.begin(), attacks.end()));

}

void bfs(int a, int b, int c){
	q.push({a,b,c});
	visited[a][b][c] = 1;
	while(q.size()){
		SCV cur = q.front(); q.pop();
		// cout << cur.a << " : " << cur.b << " : " << cur.c << "\n";

		for(int i = 0; i < attackList.size(); i++){
			int na = max(0, cur.a - attackList[i][0]);
			int nb = max(0, cur.b - attackList[i][1]);
			int nc = max(0, cur.c - attackList[i][2]);

			// cout << na << " : " << nb << " : " << nc << "\n";

			if(visited[na][nb][nc]) continue;

			visited[na][nb][nc] = visited[cur.a][cur.b][cur.c] + 1;
			if(visited[0][0][0]) break;

			q.push({na,nb,nc});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> scvs[i];
	}

	sort(attacks.begin(),attacks.end());
	get_permutation();

	bfs(scvs[0],scvs[1],scvs[2]);
	cout << visited[0][0][0] - 1 << "\n";
}
