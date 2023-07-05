import sys
import math
input = sys.stdin.readline
from heapq import heappush, heappop

N = int(input())
arr = list(map(int, input().split()))

# print(N,arr)

max_value = -100000
cur = 0
for i in range(N):
    cur += arr[i]
    max_value = max(max_value, cur)
    if cur < 0:
        cur = 0
    
print(max_value)
    