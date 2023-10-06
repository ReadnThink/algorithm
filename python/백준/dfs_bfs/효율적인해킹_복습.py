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
        for j in range(n):
            print(arr[i][j], end=' ')
        print()
    print()

def dfs(depth,visited):
    ret = 1
    
    for next in adj[depth]:
        if visited[next]:
            continue
        visited[next] = True
        ret += dfs(next,visited)
    return ret

n,m = map(int,input().split())
adj = [[] for _ in range(n+1)]
ret = [[] for _ in range(n+1)]

for i in range(m):
    a,b = map(int,input().split())
    adj[b].append(a)

max_value = 0
for i in range(1,n+1):
    visited = [False]*(n+1)
    visited[i] = True
    ret[i].append(dfs(i, visited))
    max_value = max(max_value, ret[i][0])
for i in range(1,n+1):
    if max_value == ret[i][0]:
        print(i, end=' ')



