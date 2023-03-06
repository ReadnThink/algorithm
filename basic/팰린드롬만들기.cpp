#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string str, ret = "";
int alpha[200], flag;
char mid;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    for(auto i : str) alpha[i]++;
    // for(auto i : alpha) cout << i << " ";
    for(int i = 'Z'; i >= 'A'; i--){
        if(alpha[i]){
            if(alpha[i] & 1){
                mid = char(i);
                flag++;
                alpha[i]--;
            }
            if(flag == 2) break;
            //앞뒤로 붙여넣는다.
            for(int j = 0; j < alpha[i]; j += 2){
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }

    if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag == 2) cout << "I'm Sorry Hansoo" << "\n";
    else cout << ret;
}