#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> a;
void input(){
    // 왜 시간초과?
    cin >> n;
    int c;
    for(int i = 0; i < n; i++){
        cin >> c;
        a.push_back(c);
    }
    sort(a.begin(),a.end());
    cin >> m;
    int b;
    for(int i = 0; i < m; i++){
        cin >> b;
        auto up = upper_bound(a.begin(),a.end(),b) - a.begin();
        auto down = lower_bound(a.begin(),a.end(),b) - a.begin();
        cout << up - down << ' ';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
}