#include <iostream>
#include <vector>

using namespace std;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    vector<int> v;

    int max = -1000001;
    int min = 1000001;
    for(int i = 0; i < n; i++){
        int number; cin >> number;
        v.push_back(number);

        if(max < v[i]) max = v[i];
        if(min > v[i]) min = v[i];
    }

    cout << min << " " << max << "\n";
    cout << v.size();
    return 0;
}
