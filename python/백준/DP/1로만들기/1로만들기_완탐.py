import sys
input = sys.stdin.readline
from queue import PriorityQueue
from collections import deque
sys.setrecursionlimit(1000000)
import copy

# n, m = map(int, input().split())
n = int(input().strip())
ret = 1e9
def dfs(depth, cnt):
    global ret
    # print(depth)
    if depth == 1:
        ret = min(ret, cnt)
        return
    
    if depth % 3 == 0:
        dfs(depth//3, cnt+1)
    elif depth % 2 == 0:
        dfs(depth//2, cnt+1)
    dfs(depth-1, cnt+1)

dfs(n,0)
print(ret)