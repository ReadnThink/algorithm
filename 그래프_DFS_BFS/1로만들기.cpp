#include <iostream>

using namespace std;

int N, ret;
int a[1000004];

int main(){
	cin >> N;
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;

	for(int i = 4; i <= N; i++){
		int minu = a[i - 1];
		int sec = a[i / 2];
		int third = a[i / 3];

		if(i % 3 == 0){
			if(minu > third) {
				if(third > sec) a[i] = sec + 1;
				else a[i] = third + 1;
			}
			else if(minu < third) {
				if(minu > sec) a[i] = sec + 1;
				a[i] = minu + 1;
			}
			else a[i] = minu + 1; 
		} else if(i % 2 == 0){
			if(minu > sec) a[i] = sec + 1;
			else if(minu < sec) a[i] = minu + 1;
			else a[i] = minu + 1; 
		}else a[i] = minu + 1;
	}
	// for(int i = 0; i <= N; i++){
	// 	cout << a[i] << " ";
	// }
	cout << a[N] << "\n";
}