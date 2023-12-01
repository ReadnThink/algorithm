import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque

# 수빈이가 동생을 찾는 가장 빠른 시간을 구하고 그 경우의 수가몇가지인지 구하시오 (bfs)

def bfs(n,k):
    q = deque()
    q.append((n))
    visited[n] = 1
    way[n] = 1
    while q:
        cur = q.popleft()
        
        for next in [cur+1, cur-1, cur*2]:
            if next >= 0 and next <= 100000:
                if not visited[next]:
                    q.append((next))
                    visited[next] = visited[cur] + 1
                    way[next] = way[next] + way[cur]
                elif visited[next] == visited[cur]+1:
                    way[next] = way[next] + way[cur]
    print(visited[k] - 1)
    print(way[k])

N,K = map(int, input().split())
visited = [0]*100001
way = [0]*100001
bfs(N,K)