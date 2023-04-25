#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<string> s(104);
int a[104][104];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for(int i = 0 ; i < N; i++){
		cin >> s[i];
	}

	for(int i = 0 ; i < N; i++){
		int cur = -1;
		for(int j = 0; j < M; j++){
			if(s[i][j] == 'c'){
				cur = 0;
				a[i][j] = cur;			
			}else if (s[i][j] != 'c' && cur != -1){
				a[i][j] = ++cur;
			}else{
				a[i][j] = cur;
			}
		}
	}

	for(int i = 0 ; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}