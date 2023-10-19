import sys
from heapq import heapify, heappop, heappush
input = sys.stdin.readline


n,k = map(int, input().split())
bosuk = [list(map(int, input().split())) for _ in range(n)]
bags = [int(input()) for _ in range(k)]
q = []
bosuk.sort(key=lambda x : x[0])
bags.sort(key=lambda x : x)

ret = 0
j = 0
for i in range(k):
    while j < n and bosuk[j][0] <= bags[i]:
        heappush(q, (-bosuk[j][1], bosuk[j][1]))
        j += 1
    if q:
        ret += heappop(q)[1]
print(ret)

        