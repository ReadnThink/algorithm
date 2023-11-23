import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque

def per(depth, temp):
    if depth == 3:
        candidates.append(temp[:])
        return
    for i in range(3):
        if visited[i]:
            continue
        visited[i] = True
        temp.append(ATTACK[i])
        per(depth+1, temp)
        temp.pop()
        visited[i] = False

def bfs(scvs):
    q = deque()
    q.append([scvs[0], scvs[1], scvs[2], 1])
    
    while q:
        a,b,c,cnt = q.popleft()
        
        for attack in candidates:
            na = max(0, a-attack[0])
            nb = max(0, b-attack[1])
            nc = max(0, c-attack[2])
            
            if na == 0 and nb == 0 and nc == 0:
                return cnt
            q.append([na,nb,nc,cnt+1])
    
ATTACK = [9,3,1]
N = int(input())
SCVS = list(map(int, input().split()))
while len(SCVS) < 3:
    SCVS.append(0)
ret = 0
visited = [False]*3
candidates = []

per(0,[])
print(bfs(SCVS))