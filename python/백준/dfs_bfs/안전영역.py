import sys
sys.setrecursionlimit(10000)
from collections import deque

dy = [1,-1,0,0]
dx = [0,0,1,-1]

def dfs(rain,y,x,visited,arr):
    visited[y][x] = True
    for d in range(4):
        ny = y + dy[d]
        nx = x + dx[d]
        if 0 <= ny < N and 0 <= nx < N:
            if visited[ny][nx] or arr[ny][nx] <= rain:
                continue    
            visited[ny][nx] = True
            dfs(rain,ny,nx,visited,arr)

N = int(input())
arr = []
max_limit = -1
for i in range(N):
    arr.append(list(map(int, input().split(' '))))
    max_limit = max(max_limit,max(arr[i]))

# result가 0이아닌 1인 이유 : 비의양이 1보다 작다면, 1을 반환해야한다.
result = 1
for rain in range(1, max_limit+1):
    visited = [[False for _ in range(N)] for _ in range(N)]
    cnt = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] == False and arr[i][j] > rain:
                dfs(rain,i,j,visited, arr)
                cnt += 1
    result = max(result, cnt)
print(result)