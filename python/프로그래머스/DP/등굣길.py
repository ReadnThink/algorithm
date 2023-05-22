def solution(m, n, puddles):
    dp = [[0]*m for _ in range(n)]
    MOD =  1000000007
    
    for i in range(len(puddles)):
        dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1
    
    for i in range(n):
        for j in range(m):
            if i == 0 or j == 0:
                dp[i][j] = 1
            else:
                if dp[i][j] == -1:
                    dp[i][j] = 0
                    continue
                    
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD
            
    for i in range(n):
        print(dp[i])
        
    return dp[n-1][m-1] % MOD