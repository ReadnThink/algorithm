import sys
input = sys.stdin.readline
from queue import PriorityQueue
from collections import deque
sys.setrecursionlimit(1000000)
import copy

dy = [1,-1,0,0]
dx = [0,0,1,-1]
def debug(arr):
    for i in range(n):
        for j in range(n):
            print(arr[i][j], end=' ')
        print()
    print()

def dfs(depth):
    ret = 0
    child = 0
    for next in tree[depth]:
        if next == delete:
            continue
        ret += dfs(next)
        child += 1
    
    if child == 0:
        ret += 1
    return ret

n = int(input())
arr = list(map(int,input().split()))
tree = [[] for _ in range(n)]
delete = int(input())
root = -1
for i in range(n):
    if arr[i] == -1:
        root = i
        continue
    tree[arr[i]].append(i)
if root == delete:
    print(0)
    exit()
# tree[delete] = [-1]
# print(tree)
print(dfs(root))
