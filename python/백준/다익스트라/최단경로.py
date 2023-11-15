import sys
input = sys.stdin.readline
from queue import PriorityQueue

v,e = map(int, input().split())
k = int(input())
graph = [[] for _ in range(v+1)]

for i in range(e):
    from_node,to_node,w = map(int, input().split())
    graph[from_node].append((to_node,w))

q = PriorityQueue()
visited = [False]*(v+1)
dist = [1e9]*(v+1)
dist[k] = 0
q.put((0,k))

while q.qsize():
    node = q.get()[1]
    if visited[node]:
        continue
    visited[node] = True
    for next_node, weight in graph[node]:
        if dist[next_node] > dist[node] + weight:
            dist[next_node] = dist[node] + weight
            q.put((dist[next_node], next_node))

for i in range(1,v+1):
    if dist[i] != 1e9:
        print(dist[i])
    else:
        print('INF')