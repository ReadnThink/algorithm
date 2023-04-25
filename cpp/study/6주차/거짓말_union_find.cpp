#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int parents[51];
vector<int> v[51];
vector<int> know;

int Find(int x){
	if(parents[x] == x) return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y){
	int a = Find(x);
	int b = Find(y);
	if(a < b) parents[b] = a;
	else parents[a] = b;
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 0; i < k; i++){
		int temp; cin >> temp;
		know.push_back(temp);
	}

	for(int i = 1; i <= 50; i++){
		parents[i] = i;
	}

	for(int i = 0; i < m; i++){
		int people_size; cin >> people_size;
		int person, prev; 

		for(int j = 0; j < people_size; j++){
			if(j >= 1){
				prev = person;
				cin >> person;
				Union(person, prev);
			}else {
				cin >> person;
			}
			v[i].push_back(person);
		}
	}

	for(auto list : v){
		bool flag = false;
		for(auto person : list){
			if(flag) break;
			for(auto k : know){
				if(Find(k) == Find(person)){
					m--;
					flag = true;
					break;
				}
			}
		}
	}

	cout << m << '\n';
}