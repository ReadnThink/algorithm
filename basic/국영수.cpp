#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct students{
    string name;
    int ko, en, math;
};

bool compare(students a, students b){
    if(a.ko != b.ko){
        return a.ko > b.ko;
    } else if(a.en != b.en){
        return a.en < b.en;
    } else if (a.math != b.math){
        return a.math > b.math;
    } else {
        return a.name < b.name;
    }
}

int n;
vector<students> studentList;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        students s;
        cin >> s.name >> s.ko >> s.en >> s.math;
        studentList.push_back(s);
    }

    sort(studentList.begin(), studentList.end(), compare);

    for(int i = 0; i < n; i++){
        cout << studentList[i].name << "\n";
    }

    return 0;
}
