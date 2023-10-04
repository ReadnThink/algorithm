import sys
input = sys.stdin.readline

K = int(input())
arr = input().split()
visited = [0]*10
max_value = ""
min_value = ""


def check(i,j,k):
    if k == '<':
        return i < j
    else:
        return i > j

def dfs(depth, s):
    global max_value, min_value
    
    if depth == K+1:
        if len(min_value) == 0:
            min_value = s
        else:
            max_value = s
        return
    
    for i in range(10):
        if visited[i]:
            continue
        if depth == 0 or check(s[-1], str(i), arr[depth-1]):
            visited[i] = True
            dfs(depth+1, s+str(i))
            visited[i] = False

dfs(0,"")
print(max_value)
print(min_value)

        
