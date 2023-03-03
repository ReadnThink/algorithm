#include <string>
#include <vector>
#include <set>

using namespace std;

int cnt[26];

set<char> s;

string solution(string input_string) {
    string answer = "";

    for(int i = 0; i < input_string.size(); i++){
        int alpha = input_string[i] - 'a';
        cnt[alpha]++;
        if(cnt[alpha] > 1 && input_string[i] != input_string[i - 1]){
           s.insert(input_string[i]); 
        }
    }

    set<char>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        answer += *iter;
    }
    
    if(s.empty()) answer = "N";
    
    return answer;
}