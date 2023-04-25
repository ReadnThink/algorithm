#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<string> sNums;

bool compare(const string& a, const string& b){

    // 크기 비교
    if(a.size() != b.size()){
        return a.size() < b.size();
    }
    // 2. 합 구하고 비교
    int a_sum = 0;
    int b_sum = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] >= '0' && a[i] <= '9') a_sum += a[i] - '0'; 
        if(b[i] >= '0' && b[i] <= '9') b_sum += b[i] - '0';
    }
    if(a_sum != b_sum) return a_sum < b_sum; 
    // 사전순
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        string code; cin >> code;
        sNums.push_back(code);
    }

    sort(sNums.begin(),sNums.end(), compare);

     for(int i = 0; i < n; i++){
        cout << sNums[i] << "\n";
    }
    return 0;
}
