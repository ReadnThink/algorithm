#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n, dp[31][61];
vector<char> ch;
ll go(int n, int w){ // n 알약, w 반쪽
    if(n == 0 && w == 0){
        return 1;
    }
    if(dp[n][w]) return dp[n][w];
    ll &ret = dp[n][w];
    if(n > 0){
        ret += go(n-1,w+1);
    }
    if(w > 0){
        ret += go(n,w-1);
    }
    return ret;
}

void input(){
    while(1){
        cin >> n;
        if(n == 0) break;
        cout << go(n, 0) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);    
    input();
}