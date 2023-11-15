import sys
input = sys.stdin.readline
from collections import deque

GROUND = 'L'
OCEAN = 'W'
dy = [0,0,1,-1]
dx = [1,-1,0,0]

def bfs(y,x):
    q = deque()
    visited = [[0]*m for _ in range(n)]
    q.append((y,x))
    visited[y][x] = 1
    while q:
        y,x = q.popleft()
        
        for d in range(4):
            ny = y+dy[d]
            nx = x+dx[d]
            
            if 0 <= ny < n and 0 <= nx < m and visited[ny][nx] == 0:
                if board[ny][nx] == GROUND:
                    visited[ny][nx] = visited[y][x]+1
                    q.append((ny,nx))
    return visited[y][x]-1

n,m = map(int,input().split())
board = [list(input().strip()) for _ in range(n)]


ret = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == GROUND:
            ret = max(ret, bfs(i,j))
print(ret)