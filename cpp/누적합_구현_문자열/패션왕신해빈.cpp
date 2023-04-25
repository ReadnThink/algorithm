#include <iostream>
#include <map>

using namespace std;

int n,m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        map<string,int> m1;
        cin >> m;
        for(int j = 0; j < m; j++){
            string s, t; cin >> s >> t;
            m1[t]++;
        }
        long long ret = 1;
        for(auto cnt : m1){
            ret *= (long long)cnt.second + 1;
        }
        ret--;
        cout << ret << "\n";
    }


    return 0;
}
