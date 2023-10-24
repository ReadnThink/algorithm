import sys
input = sys.stdin.readline
INF = sys.maxsize

n = int(input())
street = list(input())
dp = [INF]*n
dp[0] = 0

for i in range(1,n):
    for j in range(i):
        if street[j] == 'B' and street[i] != 'O':
            continue
        elif street[j] == 'O' and street[i] != 'J':
            continue
        elif street[j] == 'J' and street[i] != 'B':
            continue
        # print(dp[i], dp[j] + ((i-j) * 2))
        dp[i] = min(dp[i], dp[j] + pow(i-j, 2))
    
    # print(dp)
print(dp[n-1] if dp[n-1] != INF else -1)