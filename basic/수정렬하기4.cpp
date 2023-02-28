#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

bool compare(int &a, int &b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++){
        cout << v[i] << "\n";
    }
}