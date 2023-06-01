import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n - 1)]
root = [0 for _ in range(n+1)]
visited = [False for _ in range(n+1)]
# 트리 만들기
graph = [[] for _ in range(n+1)]
for i in arr:
    graph[i[0]].append(i[1])
    graph[i[1]].append(i[0])
# 탐색
def dfs(node):
    visited[node] = True
    for next in graph[node]:
        if visited[next]:
            continue   
        # 루트 저장
        root[next] = node
        dfs(next)
dfs(1)
for i in range(2,n+1):
    print(root[i])