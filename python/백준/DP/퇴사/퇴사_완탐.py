import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

n = int(input().strip())
arr = [list(map(int,input().split())) for _ in range(n)]
ret = 0

def dfs(depth, sum):
    global ret
    if depth >= n:
        ret = max(ret,sum)
        return
    
    dfs(depth+1,sum)
    if depth+arr[depth][0] <= n:
        dfs(depth+arr[depth][0], sum+arr[depth][1])

dfs(0, 0)
print(ret) 