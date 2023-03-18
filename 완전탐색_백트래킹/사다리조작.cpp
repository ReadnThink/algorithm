#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;

int N, M, H,a,b;
vector<int> v[275][275];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> H;

	for(int i = 0; i < M; i++){
		cin >> a >> b;
		v[a][b].push_back(b + 1);
	}	

	for(int o = 1; o <= M; o++){
		for(int i = 1; i <= M; i++){
			cout << o << "-" << i << " :: ";
			for(int j : v[o][i]){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	
}
