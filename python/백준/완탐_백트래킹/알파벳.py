import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

dy = [1,-1,0,0]
dx = [0,0,1,-1]

def dfs(y,x,cnt):
    global ret
    ret = max(ret, cnt)
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
            
        if 0 <= ny < n and 0 <= nx < m:
            if arr[ny][nx] in record:
                continue
            record.add(arr[ny][nx])
            dfs(ny,nx,cnt+1)
            record.remove(arr[ny][nx])

n,m= map(int, input().split())
arr = [list(map(str, input().strip())) for _ in range(n)]
record = set()
record.add(arr[0][0])
ret = 0
dfs(0,0,1)
print(ret)
