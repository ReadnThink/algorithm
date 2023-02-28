#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> hights;
int sum;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++){
        int h; cin >> h;
        hights.push_back(h);
        sum += hights[i];
    }
    sort(hights.begin(), hights.end());

    for(int i = 0; i < 9; i++){
        int result = sum;
        result -= hights[i];

        for(int j = + 1; j < 9; j++){

            result -= hights[j];

            if(result == 100){
                for(int k = 0; k < 9; k++){
                    if(k != i && k != j){
                        cout << hights[k] << "\n";
                    }
                }
                return 0;
            } else result += hights[j];
        }
    }
}
