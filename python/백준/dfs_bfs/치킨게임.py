import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)


# 집마다 가장 가까운 치킨집 찾기 
# 모든 집의 가장 가까운 치킨 거리 = 마을의 치킨거리

BLANK = 0
HOUSE = 1
CHICKEN = 2
n,m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
houses, chicken = [], []
chicken_combi = []
min_value = 1e9

for i in range(n):
    for j in range(n):
        if board[i][j] == HOUSE:
            houses.append((i,j))
        if board[i][j] == CHICKEN:
            chicken.append((i,j))
            
def combi(start, depth, temp):
    if depth == m:
        chicken_combi.append(temp[:])
        return
    for i in range(start+1, len(chicken)):
        temp.append(chicken[i])
        combi(i, depth+1, temp)
        temp.pop()

combi(-1,0,[])
for comb in chicken_combi:
    sum = 0
    for h in houses:
        dist = 1e9
        for chic in comb:
            dist = min(dist, abs(h[0]-chic[0]) + abs(h[1]-chic[1]))
        sum += dist
    min_value = min(min_value, sum)

print(min_value)