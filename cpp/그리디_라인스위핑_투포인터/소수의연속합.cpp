#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <queue>
#include <map>
typedef long long ll;
using namespace std;
const int MAX = 4000001;
int N,P, ret,sum;
bool a[MAX];
int prime[MAX];

void test_print(){
	for(int i = 2; i <= N; i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
	for(int i = 0; i <= N; i++){
		cout << prime[i] << ' ';
	}
	cout << '\n';
}

void makePrime(){
	a[0] = true;
	a[1] = true;
	for(int i = 2; i * i <= MAX; i++){
		if(a[i]) continue;
		for(int j = i * 2; j <= MAX; j += i){
			a[j] = true;
		}
	}
	for(int i = 2; i <= N; i++){
		if(!a[i]) prime[P++] = i;
	}
}

void Solution(){
	int left = 0;
	int right = 0;
	while(1){
		if(sum >= N) sum -= prime[left++];
		else if(right == P) break;
		else sum += prime[right++];

		if(sum == N) ret++;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	makePrime();
	// test_print();
	Solution();
	cout << ret << '\n';
}