import sys
input = sys.stdin.readline
from queue import PriorityQueue
from collections import deque
sys.setrecursionlimit(1000000)
import copy

dy = [1,-1,0,0]
dx = [0,0,1,-1]
def debug(arr):
    for i in range(n):
        for j in range(m):
            print(arr[i][j], end=' ')
        print()
    print()

def setting():
    global sy,sx
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 'J':
                sy,sx = i,j
            elif arr[i][j] == 'F':
                f.append([i,j])

def bfs_f(visited):
    q = deque()
    for fy,fx in f:
        q.append([fy,fx])
        visited[fy][fx] = 1
    
    while q:
        y,x = q.popleft()
        
        for d in range(4):
            ny = y+dy[d]
            nx = x+dx[d]
            
            if 0 <= ny < n and 0 <= nx < m:
                if visited[ny][nx] != -1 or arr[ny][nx] == '#':
                    continue
                visited[ny][nx] = visited[y][x] +1
                q.append([ny,nx])
    
def bfs(visited):
    q = deque()
    q.append([sy,sx])
    visited[sy][sx] = 1
    
    while q:
        y,x = q.popleft()
        if y == 0 or x == 0 or y == n-1 or x == m-1:
            return visited[y][x]
        for d in range(4):
            ny = y+dy[d]
            nx = x+dx[d]
            
            if 0 <= ny < n and 0 <= nx < m:
                if visited[ny][nx] != -1 and visited[ny][nx] <= visited[y][x]+1 or arr[ny][nx] == '#':
                    continue
                visited[ny][nx] = visited[y][x] +1
                
                q.append([ny,nx])
    return 'IMPOSSIBLE'
n,m = map(int,input().split())
arr = [list(map(str, input().strip())) for _ in range(n)]
sy,sx = 0,0
f = []
visited = [[-1]*m for _ in range(n)]
setting()

bfs_f(visited)

debug(visited)

print(bfs(visited))

debug(visited)