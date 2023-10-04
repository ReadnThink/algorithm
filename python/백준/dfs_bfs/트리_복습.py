n = int(input())
nodes = list(map(int,input().split()))
remove = int(input())

adj = [[] for _ in range(n)]
root = 0
for i in range(n):
    if nodes[i] == -1:
        root = i
        continue
    adj[nodes[i]].append(i)
    
if root == remove:
    print(0)
    exit()
# print(adj)

def dfs(depth):
    global remove
    ret = 0
    child = 0
    for next in adj[depth]:
        if next == remove:
            continue
        ret += dfs(next)
        child += 1
    
    if child == 0:
        return 1
    return ret

print(dfs(root))