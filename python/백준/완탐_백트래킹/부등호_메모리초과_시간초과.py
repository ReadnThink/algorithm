import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(1000000000)

per = []
def dfs(depth, temp, visited):
    global n
    if depth == n+1:
        per.append(temp[:])
        return
    for i,v in enumerate(nums):
        if visited[i]:
            continue
        visited[i] = True
        temp.append(v)
        dfs(depth+1, temp, visited)
        visited[i] = False
        temp.pop()

n = int(input())
arr = input().split()
nums = [0,1,2,3,4,5,6,7,8,9]
visited = [False] * 10
max_value = 0
min_value = 1e9
dfs(0,[], [False]*10)

answer = []
for candidate in per:
    is_candidate = True
    for i in range(len(arr)):
        if arr[i] == '<':
            if candidate[i] > candidate[i+1]:
                is_candidate = False
                continue
        elif arr[i] == '>':
            if candidate[i] < candidate[i+1]:
                is_candidate = False
                continue
    if is_candidate:
        ret = []
        for num in candidate:
            ret.append(str(num))
        ret = ''.join(ret)
        answer.append(ret)

print(answer[-1])
print(answer[0])



        
