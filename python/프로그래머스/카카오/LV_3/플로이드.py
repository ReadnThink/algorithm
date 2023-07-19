import sys
input = sys.stdin.readline
from queue import PriorityQueue
INF = 200 * 100_001


def floyd(dist, N):
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

N = int(input())
M = int(input())
dist = [[INF for _ in range(N)] for _ in range(N)]
for i in range(N):
    dist[i][i] = 0
for _ in range(M):
    a,b,c = map(int, input().split())
    dist[a-1][b-1] = min(dist[a-1][b-1],c)
    # dist[b-1][a-1] = min(dist[b-1][a-1],c)

floyd(dist,N)
for i in range(N):
    for j in range(N):
        if dist[i][j] == INF:
            dist[i][j] = 0
        print(dist[i][j], end=' ')
    print()
