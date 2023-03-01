#include <iostream>
#include <vector>

using namespace std;

int n, ret;
vector<int> v;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        int num = i;
        if(i == n){
            cout << 0;
        }
        while(num){
            ret += num % 10;
            num /= 10;
        }
        //종료조건
        if(ret + i == n){
            cout << i << "\n";
            break;
        }
        ret = 0;
    }
}