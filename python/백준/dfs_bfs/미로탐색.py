import sys 
sys.setrecursionlimit(10000) 
from collections import deque

dy = [0,1,0,-1]
dx = [1,0,-1,0]

def bfs(y,x, arr, visited):
    result = 0
    q = deque()
    q.append([y,x,1])
    
    
    while q:
        y,x,cnt = q.popleft()
        visited[y][x] = True
        if y == N-1 and x == M-1:
            result = cnt
            break
            
    
        for d in range(4):
            ny = y + dy[d]
            nx = x + dx[d]
            if 0 <= ny < N and 0 <= nx < M:
                if visited[ny][nx]:
                    continue
                if arr[ny][nx] == '1':
                    visited[ny][nx] = True
                    q.append([ny,nx,cnt+1])
    
    return result

N,M = map(int,input().split())
arr = []
for i in range(N):
    arr.append(input().strip())

result = bfs(0,0, arr, [[False for _ in range(M)] for _ in range(N)])
print(result)

