import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

N = int(input())
tree = [[] for _ in range(N+1)]
visited = [False]*(N+1)
answer = [0 for _ in range(N+1)]
for _ in range(1,N):
    a,b = map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)


def dfs(node):
    for next in tree[node]:
        if visited[next]:
            continue
        visited[next] = True
        answer[next] = node
        dfs(next)
visited[1] = True
dfs(1)

# print(tree)
# print(answer)
for i in range(2,len(answer)):
    print(answer[i])
    