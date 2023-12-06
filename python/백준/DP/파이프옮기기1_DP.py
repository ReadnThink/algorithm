import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque

H = 0 # 가로
V = 1 # 세로
D = 2 # 대각

N = int(input())
arr = [list(map(int,input().split())) for _ in range(N)]
dp = [[[0 for _ in range(N)] for _ in range(N)] for _ in range(3)]
dp[H][0][1] = 1

for i in range(N):
    for j in range(2,N):
        if arr[i][j] == 1:
            continue
        dp[H][i][j] = dp[H][i][j-1] + dp[D][i][j-1]
        dp[V][i][j] = dp[V][i-1][j] + dp[D][i-1][j]
        if arr[i-1][j] == 0 and arr[i][j-1] == 0:
            dp[D][i][j] = dp[H][i-1][j-1] + dp[V][i-1][j-1] + dp[D][i-1][j-1]

result = dp[H][N-1][N-1] + dp[V][N-1][N-1] + dp[D][N-1][N-1]
print(result)