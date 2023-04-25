#include <iostream>

using namespace std;
int cnt[104];
int A, B, C, sum;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> C;

    for(int i = 0; i < 3; i++){
        int tmp[2]; cin >> tmp[0] >> tmp[1];
        for(int i = tmp[0]; i < tmp[1]; i++){
            cnt[i]++;
        }
    }
    // sum 구하기
    for(int i = 0; i <= 100; i++){
        if(cnt[i]){
            if(cnt[i] == 1) sum += A;
            else if(cnt[i] == 2) sum += B * 2;
            else if(cnt[i] == 3) sum += C * 3;
        }
    }
    cout << sum;
}