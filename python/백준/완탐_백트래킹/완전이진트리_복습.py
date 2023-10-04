import sys
input = sys.stdin.readline

n = int(input())
tree = list(map(int,input().split()))
ret = [[] for _ in range(n)]

def dfs(depth, tree):
    if depth == n:
        return
    mid = len(tree) // 2
    ret[depth].append(tree[mid])
    
    dfs(depth+1, tree[:mid])
    dfs(depth+1, tree[mid:])

dfs(0,tree)
for i in ret:
    print(*i)