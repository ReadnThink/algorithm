#include <string>
#include <vector>
#include <iostream>

using namespace std;

string generations[] = {"RR", "Rr", "Rr", "rr"};
vector<string> v;

string findGeneration(int gen, int order){
    // gen이 처음부터 1, 2면 solution함수로 바로 리턴되지만
    // else문을 타고 1, 2라면 parent로 return이 된다.
    if(gen == 1) {
        return generations[1];
    }
    if(gen == 2) {
        return generations[order];
    }else{
        string parent = findGeneration(gen - 1, order / 4);
        if(parent == "RR") return "RR";
        else if (parent == "rr") return "rr";
        else {
            return generations[order % 4];
        }
    }
}

vector<string> solution(vector<vector<int>> queries) {
    for(int i = 0; i < queries.size(); i++){
        v.push_back(findGeneration(queries[i][0], queries[i][1] - 1));
    }
    return v;
}