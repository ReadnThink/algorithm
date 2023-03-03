#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printV(vector<vector<int>> v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout << v[i][j] << " ";
        }
    }
    cout << "\n";
}

int solution(vector<vector<int>> ability) {
    int answer = 0;
    // sort(ability.begin(), ability.end());
    
    do{
        printV(ability);
    }while (next_permutation(ability.begin(), ability.end()));
    return answer;
}