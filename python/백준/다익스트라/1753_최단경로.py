import sys
input = sys.stdin.readline
from queue import PriorityQueue

V,E = map(int,input().split())
K = int(input())
distance = [sys.maxsize]*(V+1)
visited = [False] * (V+1)
myList = [[] for _ in range(V+1)]
q = PriorityQueue()

for _ in range(E):
    u, v, w = map(int, input().split())
    myList[u].append((v,w))
    
# 가중치, 시작 노드
q.put((0,K))
distance[K] = 0

while q.qsize() > 0:
    current = q.get()
    c_node = current[1] # 현재 노드
    if visited[c_node]:
        continue
    visited[c_node] = True
    for tmp in myList[c_node]:
        next_node = tmp[0]
        value = tmp[1]
        if distance[next_node] > distance[c_node] + value:
            distance[next_node] = distance[c_node] + value
            q.put((distance[next_node], next_node))
            
for i in range(1, V+1):
    if visited[i]:
        print(distance[i])
    else:
        print("INF")
    