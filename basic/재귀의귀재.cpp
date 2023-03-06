#include <iostream>
#include <string.h>

using namespace std;

int n, sum;

int recursion(const char *s, int l, int r){
    sum++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        cout << isPalindrome(s.c_str()) << " ";
        cout << sum << "\n";
        sum = 0;
    }

    // printf("%d\n", isPalindrome("ABBA")); // 1
    // printf("%d\n", isPalindrome("ABC"));   // 0
}