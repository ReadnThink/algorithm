import sys
input = sys.stdin.readline
from heapq import heappush, heappop

N = int(input())
offers = [list(map(int, input().split())) for _ in range(N)]
offers.sort(key=lambda x : (x[1]))

heap = []
for price, day in offers:
    heappush(heap, price)
    while len(heap) > day:
        heappop(heap)

print(sum(heap))