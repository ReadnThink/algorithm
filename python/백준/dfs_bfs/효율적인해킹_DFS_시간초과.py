import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)

def dfs(cur, visited):
    ret = 1
    for next in adj[cur]:
        if visited[next] == True:
            continue
        visited[next] = True
        ret += dfs(next,visited)
        
    return ret

N,M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(M)]
adj = [[] for _ in range(N+1)]
dp = [[0] for _ in range(N+1)]

for i in range(len(arr)):
    adj[arr[i][1]].append(arr[i][0])

ret = -1
for i in range(1, N+1):
    visited = [[False] for _ in range(N+1)]    
    visited[i] = True
    dp[i] = dfs(i,visited)
    ret = max (ret, dp[i])
    
for i in range(1, N+1):
    if ret == dp[i]:
        print(i, end=' ')
