import sys
input = sys.stdin.readline

n = int(input())
tree = list(map(int,input().split()))
ret = [[] for _ in range(n+1)]

def dfs(tree, depth):
    mid = (len(tree) // 2)
    
    ret[depth].append(tree[mid])
    
    print(f'{tree = }')
    if len(tree) == 1:
        return
    
    dfs(tree[:mid], depth+1)
    dfs(tree[mid+1:], depth+1)

dfs(tree,0)
print(ret)
for i in ret:
    print(*i)