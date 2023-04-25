#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n,ret=987654321, team[20][20], selected[20];
void input(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &team[i][j]);
		}
	}
}

void update(){
	// A,B 팀의 맴버 구하기
	vector<int> teamA,teamB;
	for(int i = 0; i < n; i++){
		if(selected[i]){ // A팀
			teamA.push_back(i);
		}else{ //B팀
			teamB.push_back(i);
		}
	}

	int sumA = 0, sumB = 0;
	for(int i = 0; i < teamA.size(); i++){// A,B 팀의 점수 구하기
		for(int j = i + 1; j < teamA.size(); j++){
			sumA += team[teamA[i]][teamA[j]] + team[teamA[j]][teamA[i]];
			sumB += team[teamB[i]][teamB[j]] + team[teamB[j]][teamB[i]];
		}
	}

	ret = min(ret, abs(sumA - sumB));
}

void print(){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", selected[i]);
	}
	printf("\n");
}

void rec_func(int start,int depth){
	if(depth == n /2){
		update();
		// print();
	}
	for(int candi = start; candi < n; candi++){
		selected[candi] = 1;
		rec_func(candi + 1, depth + 1);
		selected[candi] = 0;
	}
}

int main(){
	input();
	rec_func(0,0);
	printf("%d\n", ret);
}