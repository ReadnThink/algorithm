n = int(input())
nodes = list(map(int,input().split()))
remove = int(input())

def dfs(delete):
    nodes[delete] = -2
    for i in range(n):
        if delete == nodes[i]:
            dfs(i)

dfs(remove)
print(nodes)
ret = 0
for i in range(len(nodes)):
    
    if nodes[i] != -2 and i not in nodes:
        print(i)
        ret += 1
        
print(ret)