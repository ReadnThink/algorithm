#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int S = 18;
	int idx = 4;

	// idx번째 비트 끄기 = S &= ~(1 << idx)
	// S &= ~(1 << idx);
 
	// idx번째 비트 바꾸기 = S ^= (1 << idx)
	// S ^= (1 << idx);


	// cout << S << '\n';

	// 최하위 비트 찾기 = (S & -S)
	// int find_min_bit = (S & -S);
	// cout << find_min_bit << '\n';

	// 크기가 n인 집합의 모든 비트를 켜기
	// (1 << n) - 1
	// int n = 5;
	// cout << (1 << n) - 1 << '\n'; // n : 4 = 15, n : 5 = 31

	// ~ 인덱스 번째의 비트 켜기
	// S |= (1 << idx) = or 연산자를이용해 구한다.
	// int turn_on_idx_bit = S |= (1 << idx);
	// cout << turn_on_idx_bit << '\n';


	// ~ 번째 인덱스 켜져있는지 확인하기
	// and & 연산지를 활용
	// if (S & (1 << idx))
	if(S & (1 << idx)){
		cout << "idx : " << idx << " is turn on.\n";
	}else {
		cout << "idx : " << idx << " is turn off.\n";
	}
}