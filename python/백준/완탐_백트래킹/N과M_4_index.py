import sys
input = sys.stdin.readline

n,m = map(int,input().split())
arr = [0 for _ in range(m)]

def dfs(start, depth):
    if depth == m:
        for i in arr:
            print(i,end=' ')
        print()
        return
    
    for i in range(start,n+1):
        arr[depth] = i
        dfs(i,depth+1)
        
dfs(1,0)