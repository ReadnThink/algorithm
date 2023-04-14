#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

int n,m,k,ret, give[10][10], energy[10][10];
vector<int> ground[10][10];

const int dy[] = {-1,-1,-1,0,0,1,1,1};
const int dx[] = {-1,0,1,-1,1,-1,0,1};

void input(){
	cin >> n >> m >> k;
	// fill(energy[0], energy[0] + 10 * 10, 5);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> give[i][j];
			energy[i][j] = 5;
		}
	}
	int a,b,c;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		ground[a - 1][b - 1].push_back(c);
	}
}

void print(){
	cout << "energy\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			cout << energy[i][j];
		}
		cout <<'\n';
	}
	cout << "tree\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(ground[i][j].size()) cout << "i = " << i << " j = " << j << '\n';
			for(auto tree : ground[i][j]){
				cout << tree;
			}
			cout << ' ';
		}
		cout << '\n';
	}
}

void dfs(int y, int x){
	for(int i = 0; i < 8; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		ground[ny][nx].push_back(1);
	}
}

void springSummer(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int die = 0;
			vector<int> temp;
			sort(ground[i][j].begin(), ground[i][j].end());
			for(int t = 0; t < ground[i][j].size(); t++){
				int tree = ground[i][j][t];
				if(energy[i][j] >= tree){
					energy[i][j] -= tree;
					temp.push_back(tree + 1);
				}else{ // 양분 추가 후 나무 제거
					die += tree / 2;
					// ground[i][j].erase(ground[i][j].begin() + t);
				}
			}
			ground[i][j].clear();
			ground[i][j] = temp;
			energy[i][j] += die;
		}
	}
}

void fall(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int t = 0; t < ground[i][j].size(); t++){
				int tree = ground[i][j][t];
				if(tree % 5 == 0){
					dfs(i,j);
				}
			}
		}
	}
}
void winter(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			energy[i][j] += give[i][j];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	input();
	while(k--){
		springSummer();
		// print();
		fall();
		winter();
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ret += ground[i][j].size();
		}
	}
	cout << ret << '\n';
	return 0;
}