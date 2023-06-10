import sys
from collections import deque
input = sys.stdin.readline

# 그래프를 탐색한다.
# map에 y,x를 넣고 4개 이상이면 map에있는 인덱스를 .으로바꾼다.
# 뿌요를 떨어트린다.
    # 아래부터 탐색해서 비어있다면 떨어트린다.
# 반복한다.

map = [list(input().strip()) for _ in range(12)]

dy = [1,-1,0,0]
dx = [0,0,1,-1]
def dfs(y,x, visited, trace,map, word):
    visited[y][x] = True
    trace.append((y,x))
    ret = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= len(map) or nx >= len(map[0]):
            continue
        if visited[ny][nx] == True or map[ny][nx] != word:
            continue
        ret += dfs(ny,nx,visited,trace,map, word)[0]
    return [ret, trace]

def remove_trace(trace):
    for t in trace:
        map[t[0]][t[1]] = '.'
    
def do_gravity():
    for i in range(11, -1, -1):
        for j in range(6):
            if map[i][j] != '.':
                # 가로로 떨어트리기
                # 애초에 셋팅을 가로 세로 역순으로 했다면 중력적용하는게 편했을거같다...
                for k in range(i,11):
                    if map[k+1][j] == '.':
                        map[k+1][j] = map[k][j]
                        map[k][j] = '.'
ret = 0
while True:
    isPop = False
    for i in range(12):
        for j in range(6):
            visited = [[False for _ in range(7)] for _ in range(13)]
            trace = []
            if map[i][j] != '.':
                info = dfs(i,j,visited,trace,map, map[i][j])
                if info[0] >= 4:
                    isPop = True
                    remove_trace(info[1])
    do_gravity() # 뿌요뿌요 떨어트리기
    if isPop:
        ret += 1
    else:
        break
    
# for i in range(12):
#     print(map[i])
    
print(ret)