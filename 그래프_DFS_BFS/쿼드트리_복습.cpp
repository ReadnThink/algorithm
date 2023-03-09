#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v(65);
int n;

bool check(int y, int x, int size){
	
	char cur = v[y][x];

	for(int i = y; i < y+size; i++){
		for(int j = x; j < x+size; j++){
			if (cur != v[i][j]) return false;
		}
	}
	return true;
}

string quadTree(int size, int y, int x){
	string ret = "";
	if(check(y,x,size) || size == 1){
		ret += v[y][x];
	}else{
		size /= 2;
		ret += "(";
		ret += quadTree(size, y, x);
		ret += quadTree(size, y, x + size);
		ret += quadTree(size, y + size, x);
		ret += quadTree(size, y + size, x + size);
		ret += ")";
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	cout << quadTree(n,0,0) << "\n";
	return 0;
}