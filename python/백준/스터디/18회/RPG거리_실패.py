import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
INF = 987654321
n = int(input())
prices = [list(map(int,input().split())) for _ in range(n)]
print(prices)
global ret
ret = INF
def dfs(depth,idx, sum):
    global ret
    if depth == n-1:
        ret = min(ret,sum)
        print(sum,idx)
        return
    if idx+2 < n and depth < n:
        idx += 2
        depth += 1
        dfs(depth, idx, sum + prices[depth][idx])
    if idx-2 <= 0 and depth < n:
        idx -= 2
        depth += 1
        dfs(depth, idx, sum + prices[depth][idx])

for i in range(n):
    dfs(0,0,prices[0][i])        
    print()
    
print(ret)
