#include <iostream>

using namespace std;

const int V = 10;
bool a[V][V], visited[V];

void dfs(int from){
	cout << from << "\n";
	visited[from] = 1;
	for(int i = 0; i < V; i++){
		if(visited[i]) continue;
		if(a[from][i]) dfs(i);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// 정점은 0 ~ 9까지 10개의 노드가 있다.
	// 1 - 2
	// 1 - 3
	// 3 - 4
	// 이를 인접행렬로 표현하시오

	//0번부터 방문 안한 노드를 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문해 출력하는 재귀 함수를 만들고 재방문을 하지 않게 구현
	a[1][2] = 1; a[1][3] = 1;
	a[3][4] = 1;

	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(!visited[i] && a[i][j]) dfs(i);
		}
	}
}