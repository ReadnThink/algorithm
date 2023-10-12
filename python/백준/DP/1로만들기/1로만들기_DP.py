import sys
input = sys.stdin.readline
from queue import PriorityQueue
from collections import deque
sys.setrecursionlimit(1000000)
import copy

# n, m = map(int, input().split())
n = int(input().strip())
dp = [-1]*(n+1)
dp[1] = 0
def dfs(depth):
    if dp[depth] != -1:
        return dp[depth]
    
    if depth % 3 == 0 and depth % 2 == 0:
        dp[depth] = min(dfs(depth//3), dfs(depth//2)) +1
    elif depth % 3 == 0:
        dp[depth] = min(dfs(depth//3), dfs(depth-1)) +1
    elif depth % 2 == 0:
        dp[depth] = min(dfs(depth//2), dfs(depth-1)) +1
    else:
        dp[depth] = dfs(depth-1) + 1
    
    return dp[depth]

print(dfs(n))