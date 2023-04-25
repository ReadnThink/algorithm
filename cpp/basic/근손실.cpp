#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, ret;
int limit = 500;
bool visited[9];
vector<int> v;

void dfs(int depth, int limit){
    if(limit < 500) return;
    if(depth == n){
        ret++;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(depth + 1, limit - k + v[i]);
            visited[i] = false;
        }
    }
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }
    dfs(0, 500);
    cout << ret;
}



// next_permutation은 오름차순이여야 하고 같은 숫자라면 처리가 되지 않는다.

// void printV(){
//     for(auto i : v) cout << i << " ";
//     cout << "\n";
// }

// main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> n >> k;
//     for(int i = 0; i < n; i++){
//         int num; cin >> num;
//         v.push_back(num);
//     }

//     sort(v.begin(), v.end());
//     cout << "\n 함수시작  \n";
//     do{
//         // printV();
//         bool check = true;
//         int limit = 500;
//         for(auto i : v) {
//             cout << i << " ..";
//             limit -= k;
//             limit += i;
//             if(limit < 500){
//                 cout << "\ncheck ! : " << i << "\n";
//                 check = false;
//                 break;
//             }   
//         }
//         cout << "\n printV  =  ";
//         printV();
//         if(check) ret++;
//     }while(next_permutation(v.begin(),v.end()));

//     cout << ret;
// }