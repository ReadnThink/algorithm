import sys
sys.setrecursionlimit(1000000)
n = int(input())
grid = [list(map(int,input().split())) for i in range(n)]

# 중간에 0이 들어있다면, 무한루프가 돌기때문에 -1로 초기화를 한다.
# 즉, dp가 -1 일때 들어가서 dp = 0이되고  이때 점프가능 횟수가 0이라면
# dp가 -1이 아니기때문에 dfs를 돌지 않는다.
# 만약 dp를 0으로 해서 시작한다면, 점프횟수가 0일때 처리를 하기 힘들어진다.

# 또는 
# if(grid[y][x]==0) return 0;
# 처럼 예외처리를 해 줄 수 있다.

dp = [[-1] * n for i in range(n)]

def dfs(y,x):
    if x == n-1 and y == n-1:
        return 1
    
    #  이미 계산한 것은 바로 반환
    if dp[y][x] > 0:
        return dp[y][x]
    
    if dp[y][x] == -1:
        dp[y][x] = 0
        cur = grid[y][x]
        if y + cur < n:
            dp[y][x] += dfs(y+cur, x)
        if x + cur < n:
            dp[y][x] += dfs(y, x+cur)
            
    return dp[y][x]
ret = dfs(0,0)     
print(ret)
# for i in range(n):
#     print(dp[i])