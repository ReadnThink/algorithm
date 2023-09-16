import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
from collections import deque

def dfs(y,x,arr, visited):
    ret = 0
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        
        if 0 <= ny < n and 0 <= nx < m:
            if visited[ny][nx]:
                continue
            if arr[ny][nx] == 1:
                arr[ny][nx] = 0
                visited[ny][nx] = True
                ret += 1
                continue
            visited[ny][nx] = True
            
            ret += dfs(ny,nx,arr,visited)
    return ret 

def printArr():
    print()
    print()
    for i in range(n):
        for j in range(m):
            print(arr[i][j], end=' ')
        print()    

n,m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]

dy = [1,-1,0,0]
dx = [0,0,1,-1]
cnt = 0
ret = 0
while True:
    visited = [[False]*m for _ in range(n)]
    visited[0][0] = True
    temp = dfs(0,0,arr,visited)
    cnt += 1
    
    printArr()
    if temp == 0:
        break
    ret = temp

print(cnt-1, ret)
# visited = valse and arr = 1: arr = 2 visited = True
# 치즈가 모두 녹아 없어지는 데 걸리는 시간과 
# 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 구하는 프로그램을 작성하시오.