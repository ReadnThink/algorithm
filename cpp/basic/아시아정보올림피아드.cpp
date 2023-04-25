#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct students{
    int nation, number, score;
};

int n;
int check[101];
vector<students> v;

bool compare(const students a, const students b){
    return a.score > b.score;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        students student;
        cin >> student.nation >> student.number >> student.score;
        v.push_back(student);
    }

    sort(v.begin(),v.end(), compare);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(check[v[i].nation] < 2){
            cnt++;
            check[v[i].nation]++;
            cout << v[i].nation << " " << v[i].number << "\n";
        }
        if(cnt == 3) break;
    }
    return 0;
}
