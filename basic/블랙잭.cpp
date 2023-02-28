#include <iostream>
#include <vector>

using namespace std;

int n,m, ret;
vector<int> v; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int number; cin >> number;
        v.push_back(number);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int sum = v[i] + v[j] + v[k];
                if(sum > ret && sum <= m) ret = sum;
            }
        }
    }

    cout << ret;
}