#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= 9; i++){
        cout << n << " * " << i << " = " << n * i << "\n"; 
    }
}