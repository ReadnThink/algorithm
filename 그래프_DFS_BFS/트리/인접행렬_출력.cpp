#include <iostream>

using namespace std;

const int V = 4;
bool a[V][V] = { 
	{0, 1, 1, 1},
	{1, 0, 1, 0},
	{1, 1, 0, 0},
	{1, 0, 0, 0},
 };

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(a[i][j]){
				cout << i << "부터 " << j << "까지 경로가 있습니다.\n";
			}
		}
	}
}