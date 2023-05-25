import sys 
sys.setrecursionlimit(10000) 

from collections import deque

t = int(input())
dy = [1,-1,0,0]
dx = [0,0,1,-1]

def dfs(y,x):
    visited[y][x] = 1
    ret = 1
    
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        
        if ny < 0 or nx < 0 or ny >= n or nx >= m:
            continue
        if visited[ny][nx] != 0 or arr[ny][nx] == 0:
            continue
        visited[ny][nx] = 1
        ret += dfs(ny,nx)
    return ret

def bfs(y,x):
    # bfs는 방문처리를항상 ny,nx에다 해야한다.
    # y,x에다하면 중복해서 방문하는 일이 생긴다. q에 들어가는순서때문이다.
    q = deque()
    q.append([y,x])
    visited[y][x] = 1
    while q:
        y,x = q.popleft()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny < 0 or nx < 0 or ny >= n or nx >= m or visited[ny][nx] == 1:
                continue
            if arr[ny][nx] == 0:
                continue
            visited[ny][nx] = 1
            q.append([ny,nx])
        

while t:
    t -= 1
    ret = 0
    m,n,k = map(int,input().split())
    arr = [[0]*m for _ in range(n)]
    visited = [[0]*m for _ in range(n)]
    for i in range(k):
        x,y = map(int,input().split())
        arr[y][x] = 1
    
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and arr[i][j] == 1:
                # cnt = dfs(i,j)
                bfs(i,j)
                ret += 1
                
    print(ret)
    # for i in range(n):
    #     print(visited[i])
    # print()