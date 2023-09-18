import sys
input = sys.stdin.readline

n,m = map(int,input().split())
arr = []
visited = [False for _ in range(n+1)]

def dfs(start, depth):
    if depth == m:
        for i in arr:
            print(i,end=' ')
        print()
        return
    
    for i in range(start,n+1):
        if visited[i]:
            continue
        visited[i] = True
        arr.append(i)
        dfs(i,depth+1)
        arr.pop()
        visited[i] = False
        
dfs(1,0)