import sys
input = sys.stdin.readline
from collections import deque

dy = [1,-1,0,0]
dx = [0,0,1,-1]

q = deque()

def bfsFire():
    for f in fire:
        q.append([f[0], f[1]])
        visited_f[f[0]][f[1]] = 1

    while q:
        y,x = q.popleft()        
        
        for i in range(4):
            ny = y+dy[i]
            nx = x+dx[i]
            
            if 0 <= ny < n and 0 <= nx < m:
                if visited_f[ny][nx] != -1 or board[ny][nx] == '#':
                    continue
                visited_f[ny][nx] = visited_f[y][x] + 1
                q.append([ny,nx])

def bfs():
    q.append([jy,jx])
    visited_f[jy][jx] = 1
    
    while q:
        y,x = q.popleft()
        if y == 0 or x == 0 or y == n-1 or x == m-1:
            return visited_f[y][x]
        
        for i in range(4):
            ny = y+dy[i]
            nx = x+dx[i]
            if 0 <= ny < n and 0 <= nx < m:
                if visited_f[ny][nx] != -1 and visited_f[ny][nx] <= visited_f[y][x] + 1 or board[ny][nx] == '#':
                    continue
                visited_f[ny][nx] = visited_f[y][x] + 1
                q.append([ny,nx])
    return -1

n,m = map(int,input().split())
board = [list(input().strip()) for _ in range(n)]
jy,jx = 0,0
fire = []
visited_f = [[-1]*m for _ in range(n)]
# visited_j = [[0]*m for _ in range(n)]
for i in range(n):
    for j in range(m):
        if board[i][j] == 'J':
            jy,jx = i,j
        if board[i][j] == 'F':
            fire.append([i,j])
bfsFire()
# for i in range(n):
#     print(visited_f[i])
# print()
ret = bfs()
# for i in range(n):
    # print(visited_f[i])

if ret != -1:
    print(ret)
else:
    print('IMPOSSIBLE')
    