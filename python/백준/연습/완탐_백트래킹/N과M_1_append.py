import sys
input = sys.stdin.readline

n,m = map(int,input().split())
visited = [False for _ in range(n)]
arr = []

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
        arr.append(i+1)
        dfs(depth + 1)
        visited[i] = False
        arr.pop()
        
dfs(0)