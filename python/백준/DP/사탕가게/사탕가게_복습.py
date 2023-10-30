import sys
input = sys.stdin.readline


while True:
    n,m = map(float, input().split())
    if n == 0:
        break
    n,m = int(n), int(m*100)
    candies = [list(map(float, input().split())) for _ in range(n)]
    dp = [0]*(m+1)
    temp = 0
    for candi in candies:
        cal, price = int(candi[0]), int(candi[1]*100)
        temp = price
        
        for cur in range(price, m+1):
            dp[cur] = max(dp[cur-price]+cal, dp[cur])
    print(dp[m])
        
