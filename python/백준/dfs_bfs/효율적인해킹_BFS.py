import sys
from collections import deque
input = sys.stdin.readline


def bfs(v):
    q = deque([v])
    cnt = 1
    visited = [False]*(N+1)
    visited[v]=True
    while q:
        cur = q.popleft()
        for i in adj[cur]:
            if visited[i]:
                continue
            visited[i] = True
            q.append(i)
            cnt += 1
    return cnt


N,M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(M)]
adj = [[] for _ in range(N+1)]


for i in range(len(arr)):
    adj[arr[i][1]].append(arr[i][0])

dp = []
for i in range(1, N+1):
    dp.append(bfs(i))

max_value = max(dp)
for i in range(len(dp)):
    if max_value == dp[i]:
        print(i+1, end=' ')