#include <iostream>
#include <vector>

using namespace std;

int N,M,J,cur,ret;
int l,r;
vector<int> v(25);


bool isInArea(int apple){
	if(l <= apple && r >= apple) return true;
	return false;
}

void dfs(int apple, int direction){
	if(isInArea(apple)) return;
	ret += 1;
	if(direction == 0){
		l += 1; r += 1;
		dfs(apple, direction);
	}else{
		l -= 1; r -= 1;
		dfs(apple, direction);
	}
}



int main(){

	cin >> N >> M >> J;

	for(int i = 0; i < J; i++){
		cin >> v[i];
	}
	
	l = 1;

	int direction = 0;
	for(int i = 0; i < J; i++){
		r = l + M - 1;
		if(l < v[i]) direction = 0;
		else if (l > v[i]) direction = 1;
		else if (isInArea(v[i])) continue;
		
		if(cur != v[i]){
			dfs(v[i], direction);
		}
	}
	cout << ret << "\n";
}