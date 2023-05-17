n = int(input())
grid = [list(map(int,input().split())) for i in range(n)]
dp = [[0] * n for i in range(n)]
ret = 0   

dp[0][0] = 1
for i in range(n):
    for j in range(n):
        if dp[i][j] and grid[i][j]:
            next = grid[i][j]
            if i + next < n:
                dp[i+next][j] += dp[i][j]
            if j + next < n:
                dp[i][j + next] += dp[i][j]
            
print(dp[n-1][n-1])