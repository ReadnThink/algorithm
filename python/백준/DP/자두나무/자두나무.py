import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

def go(idx,tree,cnt):
    if cnt < 0:
        return 0
    if idx >= n:
        return 0
    
    ret = dp[idx][tree][cnt]
    if ret != -1:
        return ret
    
    ret = max(go(idx+1,tree^1,cnt-1), go(idx+1,tree,cnt)) + (tree == jado[idx]-1)
    dp[idx][tree][cnt] = ret
    return ret
    

n,m = map(int,input().split())
jado = list(int(input()) for _ in range(n))
dp = [[[-1]*(34) for _ in range(2)] for _ in range(n)]
result = max(go(0,1,m-1), go(0,0,m))
print(result)