#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int N, M,res = 987654321, map[54][54], visited[54][54];
vector<pair<int, int>> chicken, houses;
vector<vector<int>> chickenList;

void comb(int start, vector<int> v){
	if(v.size() == M){
		chickenList.push_back(v);
		return;
	}
	for(int i = start + 1; i < chicken.size(); i++){
		v.push_back(i);
		comb(i,v);
		v.pop_back();
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
			if(map[i][j] == 1) houses.push_back({i,j});
			if(map[i][j] == 2) chicken.push_back({i,j});
		}
	}
	vector<int> v;
	comb(-1,v);

	for(vector<int> cList : chickenList){
		int ret = 0;
		for(pair<int,int> home : houses){
			int _min = 987654321;
			for(int ch : cList){
				int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
				_min = min(_min, _dist);
			}
			ret += _min;
		}
		res = min(res, ret);
	}
	cout << res << "\n";
}
