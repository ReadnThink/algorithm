import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
from collections import deque
import copy

dy = [1,-1,0,0]
dx = [0,0,1,-1]

def dfs(start, depth, temp):
    if depth == 3:
        comb.append(temp[:])
        return
    for i in range(start+1, len(candidate_walls)):
        temp.append(i)
        dfs(i, depth+1, temp)
        temp.pop()

def go_virus(y,x,temp,visited):
    visited[y][x] = True
    temp[y][x] = 2
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        
        if 0 <= ny < N and 0 <= nx < M:
            if visited[ny][nx] or temp[ny][nx] == 1 or temp[ny][nx] == 2:
                continue
            go_virus(ny,nx,temp,visited)
                    
N,M = map(int, input().split())
board = [list(map(int,input().split())) for _ in range(N)]
candidate_walls,virus, comb = [], [], []
for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            candidate_walls.append([i,j])
        if board[i][j] == 2:
            virus.append([i,j])

dfs(-1,0,[])
max_val = 0
for fir,sec,t in comb:
    temp = copy.deepcopy(board)
    temp[candidate_walls[fir][0]][candidate_walls[fir][1]] = 1
    temp[candidate_walls[sec][0]][candidate_walls[sec][1]] = 1
    temp[candidate_walls[t][0]][candidate_walls[t][1]] = 1
    
    visited = [[False] *M for _ in range(N)]
    for y,x in virus:
        go_virus(y,x,temp,visited)
    cnt1 = 0      
    # 다음에는 줄여보기           
    for i in range(N):
        for j in range(M):
            if temp[i][j] == 0:
                cnt1 += 1
                
    max_val = max(max_val, cnt1)

print(max_val)