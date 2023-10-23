import sys
import math
from heapq import heapify, heappop, heappush
input = sys.stdin.readline

def make_che():
    candidates[0] = candidates[1] = False
    
    for i in range(2, int(math.sqrt(n))+1):
        for j in range(i+i, n+1, i):
            candidates[j] = False
    ret = []
    for i in range(n+1):
        if candidates[i]:
            ret.append(i)
    return ret
n = int(input())        
candidates = [True]*(n+1)
che = make_che()
ret = 0
end, sum, limit = 0,0,len(che)
for start in range(limit):
    while sum < n and end < limit:
        sum += che[end]
        end += 1
    
    if sum == n:
        ret += 1
    sum -= che[start]
    
print(ret)
