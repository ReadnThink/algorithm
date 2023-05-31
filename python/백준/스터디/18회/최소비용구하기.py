import sys
from queue import PriorityQueue
sys.setrecursionlimit(1000000)

input = sys.stdin.readline
INF = 987654321

n = int(input())
m = int(input())

graph = [[] for _ in range(n+1)]
visited = [False]*(n+1)
dp = [INF]*(n+1)
for i in range(m):
    node,to,price = map(int,input().split())
    graph[node].append((to,price))
start, end = map(int,input().split())

q = PriorityQueue()

q.put((0,start))
dp[start] = 0

while q.qsize() > 0:
    cur = q.get()
    node = cur[1]
    if visited[node]:
        continue
    visited[node] = True
    for n in graph[node]:
        next = n[0]
        price = n[1]
        if dp[next] > dp[node] + price:
            dp[next] = dp[node] + price
            q.put((dp[next], next))

print(dp[end])

    