#include <iostream>
#include <vector>

using namespace std;

int n, ret;
string s;
int alpha[26];
vector<int> v;

main(){
    cin >> s;

    for(int i =0; i < s.length(); i++){
        alpha[s[i] - 'a']++;
    }

     for(int i =0; i < 26; i++){
        cout << alpha[i] << " ";
    }
}