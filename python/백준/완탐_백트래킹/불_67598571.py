import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque

WALL,PATH,FIRE = '#','.', 'F'
R,C = map(int, input().split())
sy,sx,fires = -1,-1,[]
arr = [list(input().strip())for _ in range(R)]
for i in range(R):
    for j in range(C):
        if arr[i][j] == 'J':
            sy,sx = i,j
        elif arr[i][j] == FIRE:
            fires.append((i,j))

def can_escape(y,x):
    return y == 0 or x == 0 or y == R-1 or x == C-1

dy = [1,-1,0,0]
dx = [0,0,1,-1]
def bfs_fire():
    q = deque()
    for y,x in fires:
        q.append((y,x))
        visited[y][x] = 1
    
    while q:
        y,x = q.popleft()
        for d in range(4):
            ny = y+dy[d]
            nx = x+dx[d]
            if 0<= ny < R and 0 <= nx < C:
                if visited[ny][nx] != -1 or arr[ny][nx] == WALL or arr[ny][nx] == FIRE:
                    continue
                if arr[ny][nx] == PATH:
                    visited[ny][nx] = visited[y][x]+1
                    q.append((ny,nx))
    
def bfs_j():
    q = deque()
    q.append((sy,sx))
    visited[sy][sx] = 1
    while q:
        y,x = q.popleft()
        
        if can_escape(y,x):
            return visited[y][x]
        
        for d in range(4):
            ny = y+dy[d]
            nx = x+dx[d]
            if 0<= ny < R and 0 <= nx < C:
                if arr[ny][nx] == WALL or arr[ny][nx] == FIRE:
                    continue
                if arr[ny][nx] == PATH:
                    if visited[y][x]+1 < visited[ny][nx] or visited[ny][nx] == -1:
                        visited[ny][nx] = visited[y][x]+1
                        q.append((ny,nx))
                    
    return 'IMPOSSIBLE'

visited = [[-1]*C for _ in range(R)]

bfs_fire()
for i in range(R):
    print(visited[i])
print(bfs_j())
for i in range(R):
    print(visited[i])

