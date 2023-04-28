#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

int n,m;
unordered_map<int,int> mp;

void input(){
    // map을 리사이징해서 시간초과인가?
    cin >> n;
    int a,b;
    for(int i = 0; i < n; i++){
        cin >> a;
        a + 10000000;
        mp[a]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> b;
        b + 10000000;
        if(mp[b]) cout << mp[b] << ' ';
        else cout << 0 << ' ';
    }
}

void solution(){

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solution();
}