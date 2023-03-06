#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m, ret;
vector<int> v;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = v[i] + v[j];
            cout << "i = " << v[i] << " j = " << v[j] <<  "\n";
            cout << "sum = " << sum << "\n";
            if(sum == m) ret++;
        }
    }
    cout << ret << "\n";
}