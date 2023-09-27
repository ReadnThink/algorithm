import sys
input = sys.stdin.readline

def curculate(op,n1,n2):
    ret = 0
    if op == '+':
        ret = n1+n2
    if op == '-':
        ret = n1-n2
    if op == '*':
        ret = n1*n2
    return ret

def dfs(depth, sum):
    global ret
    if depth == len(op):
        ret = max(ret, sum)
        return
    dfs(depth+1, curculate(op[depth], sum, nums[depth+1]))
    
    if depth+2 < len(nums):
        temp = curculate(op[depth+1],nums[depth+1], nums[depth+2])
        dfs(depth+2, curculate(op[depth],sum, temp))
    
n = int(input())
arr = input().strip()
ret = -1e9
nums = []
op = []
for i in arr:
    if i.isdigit():
        nums.append(int(i))
    else:
        op.append(i)
print(nums, op)
dfs(0, nums[0])
print(ret)