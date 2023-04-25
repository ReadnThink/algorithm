#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int n, ret;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        string tmp; cin >> tmp;
        stack<char> s;
        // cout << "word = " << tmp << "\n";
        for(int j = 0; j < tmp.size(); j++){
            if(s.size() && s.top() == tmp[j]) s.pop();
            else s.push(tmp[j]);
        }
        if (s.empty()) ret++;
    }
    cout << ret << "\n";
}