#include <iostream>
#include <vector>

using namespace std;

int N, white_paper, blue_paper;

vector<vector<int>> v(130,vector<int>(130, 0));

bool check(int size, int y, int x){
	int cur = v[y][x];
	for(int i = y; i < y + size; i++){
		for(int j = x; j < x + size; j++){
			if(cur != v[i][j]) return false;
		}
	}
	return true;
}

void dividePaper(int size, int y, int x){

	if(check(size, y, x) || size == 1){
		if(v[y][x] == 0) white_paper++;
		else blue_paper++;
	}else{
		size /= 2;

		dividePaper(size, y, x);
		dividePaper(size, y, x + size);
		dividePaper(size, y + size, x);
		dividePaper(size, y + size, x + size);

	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			 cin >> v[i][j];
		}
	}
	dividePaper(N,0,0);
	cout << white_paper << "\n";
	cout << blue_paper << "\n";
}