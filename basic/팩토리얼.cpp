#include <iostream>

using namespace std;

int n;

int f(int n){
    if(n == 0 || n == 1) return 1;
    return n * f(n - 1);
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cout << f(n);
    return 0;
}