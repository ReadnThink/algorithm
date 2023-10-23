import sys
input = sys.stdin.readline

N, L = map(int, input().split())
water = [list(map(int,input().split())) for _ in range(N)]

water.sort(key=lambda x : x[0])    

start, result = 0,0

for s,e in water:
    if start < s:
        start = s
        
    while start < e:
        # print('start = ',start)
        start += L
        # print('start plus = ',start)
        result += 1
    # print()

print(result)
