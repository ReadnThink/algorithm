import sys

N,M = map(int, input().split())
J = int(input())
nums = [int(input()) for _ in range(J)]
result = 0
start = 1
end = M
for cur in nums:
    if start <= cur <= end:
        continue
    if cur > end:
        move = cur - end
        # print(move, cur)
        result += move
        start += move
        end += move
    else:
        move = start - cur
        # print(move, cur)
        result += move
        start -= move
        end -= move
        
print(result)
