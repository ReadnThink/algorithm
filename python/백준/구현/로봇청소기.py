import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
dy = [-1,0,1,0]
dx = [0,1,0,-1]
n,m = map(int,input().split())
ry,rx,d = map(int,input().split())
grid = [list(map(int,input().split())) for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]
visited[ry][rx] = 1
global ret
ret = 0
def dfs(y,x,d):
    global ret
    
    if grid[y][x] == 0:
        grid[y][x] = 2
        ret += 1
        
    can_clean = False
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        
        if ny < 0 or nx < 0 or ny >= n or nx >= m or grid[ny][nx] != 0:
            continue
        can_clean = True
    
    if can_clean:
        # 청소가 가능하다면
        for i in range(4):
            nd = ((d+3)-i) % 4 
            ny = y + dy[nd]
            nx = x + dx[nd]
            if ny < 0 or nx < 0 or ny >= n or nx >= m or grid[ny][nx] != 0:
                continue
            visited[ny][nx] = visited[y][x] + 1
            dfs(ny,nx,nd)
    else:
        # 후진
        by = y + dy[(d+2) % 4]
        bx = x + dx[(d+2) % 4]
        if by < 0 or bx < 0 or by >= n or bx >= m:
                return
        # 벽이면 종료
        if grid[by][bx] == 1:
            print(ret)    
            # for i in range(n):
            #     print(visited[i])
            exit(0)
        # 벽이 아니면 다시 탐색
        dfs(by,bx,d)
        
dfs(ry,rx,d)
print(ret)
