#include <iostream>
#include <algorithm>

using namespace std;

string str, tmp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    tmp = str;

    reverse(tmp.begin(), tmp.end());
    if(tmp == str) cout << 1;
    else cout << 0;

}