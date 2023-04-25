#include <iostream>
#include <algorithm>

using namespace std;

int n;
string str, startStr, lastStr;

int main(){
     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

     cin >> n >> str;
     int idx = -1;
     for(int i = 0; i < str.size(); i++){
        if(str[i] == '*'){
            idx = i;
            break;
        }
     }
    
    startStr = str.substr(0, idx);
    lastStr = str.substr(idx + 1, str.size());

     for(int i = 0; i < n; i++){
        string tmp; cin >> tmp;
        if(startStr.size() + lastStr.size() > tmp.size()){
            cout << "NE" << "\n";
            continue;
        } 
        string tmpA = tmp.substr(0, startStr.size());
        string tmpB = tmp.substr(tmp.size() - lastStr.size(), tmp.size());

        if(startStr == tmpA && lastStr == tmpB) cout << "DA" << "\n";
        else cout << "NE" << "\n";
     }

}