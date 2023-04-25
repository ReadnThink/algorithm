#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
int N,M,ret, visited[104][104];
string s;
vector<string> heard;
vector<string> seen;
map<string,int> list;
void input(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> s;
		list[s]++;
	}

	for(int i = 0; i < M; i++){
		cin >> s;
		list[s]++;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	for(pair<string,int> p : list){
		if(p.second == 2){
			ret++;
		} 
	}
	cout << ret << '\n';
	for(pair<string,int> p : list){
		if(p.second == 2){
			cout << p.first << "\n"	;
		} 
	}

}