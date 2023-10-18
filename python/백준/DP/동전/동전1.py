import sys
input = sys.stdin.readline

n,k = map(int, input().split())
coins = list(int(input().strip()) for _ in range(n))
ret = 0

dp = [0]*(k+1)
dp[0] = 1

for coin in coins:
    for i in range(coin, k+1):
        dp[i] = dp[i-coin] + dp[i]
    # print(dp)
print(dp[k])
    
        