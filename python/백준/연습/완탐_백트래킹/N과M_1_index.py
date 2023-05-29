import sys
input = sys.stdin.readline

n,m = map(int,input().split())
visited = [False for _ in range(n)]
arr = [0 for _ in range(m)]

def dfs(depth):
    global arr
    if depth == m:
        for i in arr:
            print(i, end=' ')
        print()
        return
    
    for i in range(n):
        if visited[i]:
            continue
        visited[i] = True
        arr[depth] = i+1
        dfs(depth + 1)
        visited[i] = False
        
dfs(0)