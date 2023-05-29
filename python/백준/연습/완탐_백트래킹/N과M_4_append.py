import sys
input = sys.stdin.readline

n,m = map(int,input().split())
arr = []

def dfs(start, depth):
    if depth == m:
        for i in arr:
            print(i,end=' ')
        print()
        return
    
    for i in range(start,n+1):
        arr.append(i)
        dfs(i,depth+1)
        arr.pop()
        
dfs(1,0)