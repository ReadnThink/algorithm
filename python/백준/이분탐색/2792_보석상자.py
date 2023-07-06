import sys
import math
input = sys.stdin.readline
from heapq import heappush, heappop

N,M = list(map(int, input().split()))
arr = [int(input()) for _ in range(M)]

# N명이하로 나눠줄 수 있는지?
def check(mid):
    num = 0
    for i in range(M):
        num += arr[i] // mid
        if arr[i] % mid:
            num += 1
    print(f'{mid=},{num=}')
    return N >= num # N명 보다 더 많이 나눠주면 안된다.
        

start = 1
end = max(arr)
result = 987654321
while start <= end:
    mid = (start + end) // 2
    print(start,end, mid, end=' ')
    if check(mid):
        # 가능하면 최소값을 구하기 때문에 end를 내린다.
        print('가능!')
        result = min(result,mid)
        end = mid-1
    else:
        # 가능하면 최소값을 구하기 때문에 end를 내린다.
        print('불가능!')
        start = mid+1

print(result)