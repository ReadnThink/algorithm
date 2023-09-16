import sys
input = sys.stdin.readline
from queue import PriorityQueue

V,E = map(int, input().split())
start_vertex = int(input())
edges = [[] for _ in range(V+1)]
INF = int(1e9)
dist = [INF]*(V+1)
visited = [False]*(V+1)

for _ in range(E):
    u,v,weight = map(int, input().split())
    edges[u].append([v,weight])
    
q = PriorityQueue()

# 우선순위 큐에는 [가중치, 노드]를 넣어 노드의 가중치를 나타낸다.
# 가중치를 먼저 넣어야 정렬이 되기떄문이다. Default : 최소힙
q.put([0, start_vertex])
dist[start_vertex] = 0

while q.qsize():
    cur = q.get()
    c_weight,c_vertex = cur[0], cur[1]
    if visited[c_vertex]:
        continue
    visited[c_vertex] = True
    
    for edge in edges[c_vertex]:
        next_vertex, value = edge[0], edge[1]
        if dist[next_vertex] > dist[c_vertex] + value:
            dist[next_vertex] = dist[c_vertex] + value
            q.put([dist[next_vertex], next_vertex])
    
for i in range(1, V+1):
    if visited[i]:
        print(dist[i])
    else:
        print("INF")

