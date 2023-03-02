#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> childs;
vector<int> tmp;

void dfs(int depth){
    if(tmp.size() == 7 && accumulate(tmp.begin(), tmp.end(), 0) == 100){
        sort(tmp.begin(), tmp.end());
        for(auto i : tmp) cout << i << "\n";
        exit(0); //찾는경우 재귀를 종료하는게 아닌 프로그램 전체를 종료
        return;
    }
    if(depth >= 9) return;

    //현재 depth의 난쟁이 추가
    tmp.push_back(childs[depth]);
    dfs(depth + 1);
    //현재 depth의 난쟁이 제거 후 재귀
    tmp.pop_back();
    dfs(depth + 1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int c;
    for(int i = 0; i < 9; i++){
        cin >> c;
        childs.push_back(c);
    }

    dfs(0);
    return 0;
}