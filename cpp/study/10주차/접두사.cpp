#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int n,ret, check[51];
vector<string> v;
void input(){
    cin >> n;
    string temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
    }
}

void output(){
    cout << ret << '\n';
}

void solve(){
    sort(v.begin(), v.end());
    memset(check,1,sizeof(check));
    for(int i = 0; i < v.size(); i++){
        for(int j = i +1; j < v.size(); j++){
            string temp = v[j].substr(0,v[i].size());
            // cout << v[i] << " :: " << temp  << '\n';
            if(temp == v[i]){
                check[i] = false;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(check[i]) ret++;
    }
}

int main(){
    input();
    solve();
    output();
}