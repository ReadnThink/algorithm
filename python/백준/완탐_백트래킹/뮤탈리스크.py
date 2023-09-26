import sys
input = sys.stdin.readline
from collections import deque

PER = []
def per(depth, visited, arr):
    if depth == n:
        PER.append(arr[:])
        return
    for i in range(3):
        if visited[i]:
            continue
        visited[i] = True
        arr.append(attacks[i])
        per(depth+1,visited,arr)
        visited[i] = False
        arr.pop()

ret = 1e9       
def bfs():
    global ret
    q = deque()
    q.append([scv[0],scv[1],scv[2], 1])
    
    while q:
        a,b,c,cnt = q.popleft()
        
        for attack in PER:
            na = a - attack[0]
            nb = b - attack[1]
            nc = c - attack[2]
            
            if na <= 0 and nb <= 0 and nc <= 0:
                ret = min(ret, cnt)
                continue
            q.append([na,nb,nc,cnt+1])

n = int(input())
scv = list(map(int, input().split()))
attacks = [9,3,1]
per(0,[False]*n,[])
bfs()
print(ret)
