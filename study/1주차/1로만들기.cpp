#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int N, dp[1000004];
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= N; i++) {
        if(i % 3 == 0 && i % 2 == 0) {
            dp[i] = min(dp[i - 1], min(dp[i / 3], dp[i/2])) + 1;
        }
        else if(i % 3 == 0){
            dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
        }
        else if(i % 2 == 0){
             dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
        }else{
            dp[i] = dp[i - 1] + 1;
        }
    }
    cout << dp[N] << "\n";
}

