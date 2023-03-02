#include <iostream>
#include <vector>

using namespace std;

string str;

int makeChar(char a){
    for(int j = 0; j < 13; j++){
        if(a == 'z' || a == 'Z'){
            a -= 25;
        }
        else a++;
    }
    return a;
}

int main(){
     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
     getline(cin, str);

    // 문자열을 받고 13개씩 밀어서 출력한다.
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            str[i] = makeChar(str[i]);
    }
    cout << str << '\n';

    // z일경우 a로 돌아와야한다.
}