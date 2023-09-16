
def dfs(cur):
    leaf = 0
    child = 0
    
    for next in adj[cur]:
        if next == remove:
            continue
        leaf += dfs(next)
        child += 1
    if child == 0:
        return 1
    return leaf

n = int(input())
nodes = list(map(int,input().split()))
remove = int(input())
root = -111
adj = [[] for _ in range(n+1)]
for i in range(n):
    if nodes[i] == -1:
        root = i
    else:
        adj[nodes[i]].append(i)

if remove == root:
    print(0)
else:
    print(dfs(root))