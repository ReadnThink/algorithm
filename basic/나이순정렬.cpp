#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct users{
    int id;
    int age;
    string name;
};

vector<users> v;
int n;

bool compare(users a, users b){
    if(a.age != b.age){
        return a.age < b.age;
    }
    else return a.id < b.id;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    users user;
    for(int i = 0; i < n; i++){
        cin >> user.age >> user.name;
        user.id = i;
        v.push_back(user);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++){
        cout << v[i].age << " " << v[i].name << "\n";
    }
}