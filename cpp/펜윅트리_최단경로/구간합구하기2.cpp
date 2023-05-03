#include <bits/stdc++.h>
using namespace std;
int n,m,k,tree_hight,tree_size,tree_lef;
vector<int> tree;
void make_tree(){
    int temp = n;
    while(temp){
        temp /= 2;
        tree_hight++;
    }

    
    tree_lef = pow(2,tree_hight);
    tree_size = (tree_lef) * 2;
    tree.resize(tree_size);
    cout << "tree_hight = "<< tree_hight << '\n';
    cout << "tree_lef = "<< tree_lef << '\n';
    cout << "tree size = "<< tree.size() << '\n';
    for(int i = 0; i < n; i++){
        cin >> tree[i + tree_lef];
    }
    for(auto i : tree) cout << i << ' ';
    cout << '\n';

    for(int i = tree_lef + n - 1; i > 1; i--){
        cout << i << ' ';
        tree[i/2] += tree[i];
    }
    cout << '\n';
    for(auto i : tree) cout << i << ' ';
    cout << '\n';

}

void update(int idx, int value){
    // 인덱스를 트리인덱스로 변경
    long diff = value - tree[idx];

    //루트노드 갈때까지 반복
    while(idx > 0){
        // 부모노드에 자식노드를 더해준다.
        tree[idx] = tree[idx] + diff;
        idx = idx / 2;
    }
}

void get_sum(int s, int e){
    long partSum = 0;

    while(s <= e){
        if(s % 2 == 1){
            partSum = partSum + tree[s];
        }
        if(e % 2 == 0){
            partSum = partSum + tree[e];
        } 

        s = (s+1) / 2;
        e = (e-1) / 2;
    }
    cout << partSum << '\n';
}

void input(){
    cin >> n >> m >> k;

    make_tree();

    m += k;
    int a,b,c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;

        if(a == 1){
            update(b + tree_lef - 1,c);
        }else{
            get_sum(b + tree_lef - 1,c + tree_lef - 1);
        }
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);    
    input();
}