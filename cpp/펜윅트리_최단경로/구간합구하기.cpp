#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> tree;


int get_tree_height(int l);
void setTree(int i);
void chageVal(int index, long val);
long getSum(int s, int e);

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    int tree_height = 0;
    int length = N;

    tree_height = get_tree_height(length); // 트리 높이 구하기
    cout << "treeheight = " << tree_height << '\n';
    // 트리 사이즈 구하기
    int treeSize = int(pow(2, tree_height + 1));
    cout << "tree_size = " << treeSize << '\n';
    int leftNodeStartIdx = treeSize / 2;

    //벡터 사이즈 초기화하기
    tree.resize(treeSize + 1);

    // 초기 리프노드 셋팅
    for(int i = leftNodeStartIdx; i < leftNodeStartIdx + N; i++){
        cin >> tree[i];
    }
    //구간합 구하기
    setTree(treeSize - 1);

    // 질의 받기
    for(int i = 0; i < M + K; i++){
        long a,s,e;
        cin >> a >> s >> e;
        if(a == 1){ // 데이터 변경
            chageVal(leftNodeStartIdx - 1 + s, e);
        }
        else if(a == 2){ // 2라면 구간합 구하기
            s = s + leftNodeStartIdx - 1;
            e = e + leftNodeStartIdx - 1;
            cout << getSum(s,e) << '\n';
        }
    }
    cout << "tree! \n";
    for(int i = 0; i <= treeSize; i++){
        cout << tree[i] << ' ';
    }
}
long getSum(int s, int e){
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
    return partSum;
}

void chageVal(int index, long val){
    // 인덱스를 트리인덱스로 변경
    long diff = val - tree[index];

    //루트노드 갈때까지 반복
    while(index > 0){
        // 부모노드에 자식노드를 더해준다.
        tree[index] = tree[index] + diff;
        index = index / 2;
    }
}

void setTree(int i){
    //루트노드 갈때까지 반복
    while(i != 1){
        // 부모노드에 자식노드를 더해준다.
        tree[i/2] += tree[i];
        i--;
    }
}

int get_tree_height(int l){
    int cnt = 0;
    while(l != 0){
        l /= 2;
        cnt++;
    }
    return cnt;
}