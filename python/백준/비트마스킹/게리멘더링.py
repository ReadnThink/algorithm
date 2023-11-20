import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

RED = 1
BLUE = 0
N = int(input())
strictPeople = list(map(int, input().split()))
strictPeople.insert(0,0)
graph = [[] for _ in range(N+1)]
for i in range(1,N+1):
    temp = list(map(int, input().split()))
    for j in range(1,temp[0]+1):
        graph[i].append(temp[j])
        
ret = 1e9

def dfs(cur, color, visited):
    visited[cur] = True
    visitCnt = 1
    result = [visitCnt, strictPeople[cur]]
    for next in graph[cur]:
        if visited[next]:
            continue
        if twoColor[next] != color:
            continue
        temp = dfs(next, color, visited)
        result[0] += temp[0]
        result[1] += temp[1]
    return result

for i in range(1, 1<<N-1):
    twoColor = [0]*(N+1)
    visited = [False]*(N+1)
    idx1,idx2 = -1,-1
    for j in range(N):
        if i & (1<<j):
            twoColor[j+1] = RED
            idx1 = j+1
        else:
            twoColor[j+1] = BLUE
            idx2 = j+1
    red = dfs(idx1,RED, visited)
    blue = dfs(idx2,BLUE,visited)
    
    if red[0]+blue[0]==N:
        # print(f'{twoColor=}')
        # print(f'{red=}, {blue=}')
        # print()
        ret = min(ret, abs(red[1]-blue[1]))
print(-1 if ret == 1e9 else ret)