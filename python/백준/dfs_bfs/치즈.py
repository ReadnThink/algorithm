import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
from collections import deque

n,m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
dy = [1,-1,0,0]
dx = [0,0,1,-1]

# 1이면 0으로 바꾸고 방문처리

def dfs(y,x):
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        
        if ny < 0 or nx < 0 or ny >= n or nx >= m or visited[ny][nx]:
            continue
        if arr[ny][nx] == 1:
            visited[ny][nx] = True
            arr[ny][nx] = 0
            continue
        visited[ny][nx] = True
        dfs(ny,nx)

def bfs(y,x):
    q = deque()
    q.append([y,x])
    visited[y][x] = True
    
    while q:
        y,x = q.popleft()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if ny < 0 or nx < 0 or ny >= n or nx >= m or visited[ny][nx]:
                continue
            if arr[ny][nx] == 1:
                visited[ny][nx] = True
                arr[ny][nx] = 0
                continue
            visited[ny][nx] = True
            q.append([ny,nx])
            
def checkCheese():
    cnt = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1:
                cnt += 1
    
    return cnt

ret = 0
cheeses = checkCheese()
while True:
    ret += 1
    visited = [[False]*m for _ in range(n)]
    visited[0][0] = True
    # dfs(0,0)
    bfs(0,0)
    
    # print("visited")
    # for i in range(n):
    #     print(visited[i])
    # print("arr")
    # for i in range(n):
    #     print(arr[i])
    # print()
    if checkCheese() == 0:
        break
    cheeses = checkCheese()

print(ret)
print(cheeses)
        