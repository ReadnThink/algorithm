import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
from collections import deque

dy = [1,-1,0,0]
dx = [0,0,1,-1]
def bfs(y,x):
    visited = [[0]*m for _ in range(n)]
    q = deque()    
    q.append([y,x])
    visited[y][x] = 1
    while q:
        y,x = q.popleft()
        for i in range(4):
            ny = y+dy[i]
            nx = x+dx[i]
            
            if 0 <= ny < n and 0 <= nx < m:
                if visited[ny][nx] or arr[ny][nx] == 'W':
                    continue
                visited[ny][nx] = visited[y][x]+1
                q.append([ny,nx])
                
    return visited[y][x]-1
n,m = map(int,input().split())
arr = [list(input().strip()) for _ in range(n)]


ret = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'L':
            ret = max(ret, bfs(i,j))
            
print(ret)