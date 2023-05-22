def solution(triangle):
    n = len(triangle)
    m = len(triangle[-1])
    dp = [[0]*m for _ in range(n)]
    
    dp[0][0] = triangle[0][0]
    mx = 0
    for i in range(1,n):
        for j in range(len(triangle[i])):
            dp[i][j] = max(dp[i -1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
            mx = max(mx,dp[i][j]);
    
    
    # for i in range(n):
        # print(dp[i])
        
    return mx