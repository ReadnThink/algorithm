import sys
from collections import deque
input = sys.stdin.readline

n = int(input().strip())
arr = [list(map(int, input().split())) for _ in range(n)]
arr.sort(key=lambda x : (x[1],x[0]))
    
end_time = 0
ret = 0
for start, end in arr:
    if end_time <= start:
        end_time = end
        ret += 1

print(ret)