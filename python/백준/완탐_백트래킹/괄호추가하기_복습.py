import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque

def inputV():
    ops = []
    nums = []
    for i in range(len(arr)):
        if i % 2 == 0:
            nums.append(int(arr[i]))
        else:
            ops.append(arr[i])
    return ops, nums    

def cur(op, a, b):
    sum = 0
    if op == '+':
        sum = a+b
    if op == '-':
        sum = a-b
    if op == '*':
        sum = a*b
    return sum

def dfs(curNum, depth):
    global ret
    if depth == len(ops):
        ret = max(ret, curNum)
        return
    
    dfs(cur(ops[depth], curNum, nums[depth+1]),depth+1)
    if depth+1 < len(ops):
        dfs(cur(ops[depth],curNum, cur(ops[depth+1], nums[depth+1], nums[depth+2])), depth+2)


N = int(input())
arr = list(map(str, input().strip()))
ret = -1e9
ops ,nums = inputV()
dfs(nums[0], 0)
print(ret)