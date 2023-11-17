import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

N,L,R = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

# 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다.

def check(y,x,ny,nx):
    a = arr[y][x]
    b = arr[ny][nx]
    diff = abs(a-b)
    return L <= diff <= R

dy = [1,-1,0,0]
dx = [0,0,1,-1]
def dfs(y,x, nations):
    nations.append((y,x))
    for d in range(4):
        ny = dy[d]+y
        nx = dx[d]+x
        
        if 0<=ny<N and 0<=nx<N:
            if visited[ny][nx]:
                continue
            if check(y,x,ny,nx):
                visited[ny][nx] = True
                dfs(ny,nx,nations)
    return nations

def union(nations):
    n = len(nations)
    sum = 0
    for y,x in nations:
        sum += arr[y][x]
    people = sum // n
    for y,x in nations:
        arr[y][x] = people

ret = 0
while True:
    is_union = False
    visited = [[False] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                visited[i][j] = True
                nations = dfs(i,j,[])
                if len(nations) >= 2:
                    union(nations)
                    is_union = True
    if is_union == False:
        break
    ret += 1
    
    
print(ret)