import sys
import math
input = sys.stdin.readline
from heapq import heappush, heappop

N, L = map(int, input().split())

circle = []
for i in range(N):
    start, end = map(int, input().split())
    circle.append([start, end])

circle.sort(key=lambda x : x[0])

start = 0
result = 0
for s,e in circle:
    if start < s:
        start = s
    
    while start < e:
        start += L
        result += 1

print(result)