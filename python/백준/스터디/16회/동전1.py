n, k = map(int, input().split())
coins = [int(input()) for i in range(n)]
ret = 0
dp = [0] * (k+1)
dp[0] = 1
for coin in range(len(coins)):
    for i in range(coins[coin], k+1):
        dp[i] += dp[i - coins[coin]]
        
print(dp[k])