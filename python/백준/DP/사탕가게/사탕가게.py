import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

while True:
    n,m = map(float, input().split())
    if n == 0:
        break
    n,m = int(n), int(m*100)
    candies = [list(map(float, input().split())) for _ in range(n)]
    dp = [0]*(m+1)
    for c,p in candies:
        c,p = int(c),int(p)*100
        for i in range(p,m+1):
            dp[i] = max(dp[i-p]+c, dp[i])
    print(dp[m])