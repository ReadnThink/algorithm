#include <iostream>
#include <map>

using namespace std;

int n,m;
map<string,int> m1;
map<int, string> m2;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        m1[s] = i;
        m2[i] = s;
    }
 // cout << "finish------------- \n";

    for(int i = 0; i < m; i++){
        string s; cin >> s;
        if(atoi(s.c_str()) == 0){
            //문자라는뜻
            cout << m1[s] << "\n";
        } else {
            //숫자라는 뜻
            cout << m2[atoi(s.c_str())] << "\n";
        }
    }
    return 0;
}