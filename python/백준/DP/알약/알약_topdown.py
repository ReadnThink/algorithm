import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

def go(w, h):
    if dp[w][h] != -1:
        return dp[w][h]
    dp[w][h] = 0
    
    if w == 0: # H만 남았을 경우에는 남은 H를 모두 사용하여 만드는 문자 하나의 경우만 존재
        dp[w][h] = 1
        return dp[w][h]
    if h < 0: # H가 음수 개 되는 경우는 없기 때문에 0을 리턴 
        return 0

    # W를 사용한 경우 + H를 사용한 경우 
    dp[w][h] = go(w - 1, h + 1) + go(w, h - 1)
    return dp[w][h]

dp = [[-1]*(31) for _ in range(31)]
while True:
    n = int(input())
    if n == 0:
        break
    print(go(n-1,1))