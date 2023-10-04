import sys

N,M = map(int, input().split())
J = int(input())
nums = [int(input()) for _ in range(J)]

ret = 0
start = 1
end = M

def can_catch(n):
    if start <= n <= end:
        return True
    return False

def move(n):
    global end, start, ret
    diff = 0
    if n > end:
        diff = n - end
        end += diff
        start += diff
    else:
        diff = start - n
        end -= diff
        start -= diff
    ret += diff
    
for n in nums:
    if can_catch(n):
        continue
    else:
        move(n)


print(ret)
