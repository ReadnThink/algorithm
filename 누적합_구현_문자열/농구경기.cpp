#include <iostream>
#include <vector>

using namespace std;

int firstAlpha[26];
char alpha[26];
int n;

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        // 첫글자가 같은 5명을 뽑는다.
        string tmp; cin >> tmp;
        int idx = tmp.substr(0, 1)[0] - 'a';
        firstAlpha[idx]++;
        alpha[idx] = tmp.substr(0, 1)[0];
    }
    bool check = false;
    for(int i = 0; i < 26; i++){
        if(firstAlpha[i] >= 5){
            cout << alpha[i];
            check = true;
        }
    }
    // 없으면  "PREDAJA" (따옴표 없이)를 출력한다.
    if(!check) cout << "PREDAJA";
}
