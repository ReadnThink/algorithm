#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> hights;

void printV(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++){
        int h; cin >> h;
        hights.push_back(h);
    }
    sort(hights.begin(), hights.end());

    do{
        int sum = 0;
        for(int i = 0; i < 7; i++) sum += hights[i];
        // printV(hights);
        if(sum == 100) break;
    }while(next_permutation(hights.begin(), hights.end()));
    for(int i = 0; i < 7; i++) cout << hights[i] << "\n";

}
