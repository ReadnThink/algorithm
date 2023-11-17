import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

dp = [[[0]*3 for _ in range(N)]for _ in range(N)]
def dfs(y,x,dir): # Right:0,  대각:1, Down:2
    if x == N-1 and y == N-1:
        return 1
    result = dp[y][x][dir]
    if result != 0:
        return result
    
    # 3가지 경우
    canMoveRight = x+1 < N and arr[y][x+1] == 0
    canMoveDown = y+1 < N and arr[y+1][x] == 0
    
    if canMoveRight and dir != 2:
        result += dfs(y,x+1,0)
    if canMoveDown and dir != 0:
        result += dfs(y+1,x,2)
    if canMoveRight and canMoveDown and arr[y+1][x+1] == 0:
        result += dfs(y+1,x+1,1)
    
    dp[y][x][dir] = result
    return result
    
print(dfs(0,1,0))
