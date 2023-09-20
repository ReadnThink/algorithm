import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

dy = [1,-1,0,0]
dx= [0,0,1,-1]
def dfs(y,x,arr,visited,contries):
    contries.append([y,x])
    sum = arr[y][x]
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        
        if 0 <= ny < N and 0 <= nx < N:
            if visited[ny][nx]:
                continue
            if L <= abs(arr[y][x] - arr[ny][nx]) <= R:
                visited[ny][nx] = True
                sum += dfs(ny,nx,arr,visited,contries)
    return sum
                
N,L,R = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

res = 0
while True:
    is_move = False
    visited = [[False]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                visited[i][j] = True
                contries = []
                sum = dfs(i,j,arr,visited,contries)
                
                if len(contries) > 1:
                    for y,x in contries:
                        arr[y][x] = sum // len(contries)
                    is_move = True
    if not is_move:
        break
    res += 1

print(res)