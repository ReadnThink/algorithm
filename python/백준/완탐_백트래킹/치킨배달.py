import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)

def dfs(start, depth, temp):
    if depth == M:
        candidates.append(temp[:])
        return
    for i in range(start+1, len(chicken)):
        temp.append(i)
        dfs(i, depth+1, temp)
        temp.pop()

N,M = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]

house = []
chicken = []
for i in range(N):
    for j in range(N):
        if arr[i][j] == 1:
            house.append([i+1,j+1])
        if arr[i][j] == 2:
            chicken.append([i+1,j+1])

candidates = []
dfs(-1,0,[])        
# print(f'{candidates=}')
# print(f'{house=}')
# print(f'{chicken=}')

# ret = 1e9
# for candi in candidates:
#     cnt = 0
#     for hy,hx in house:
#         min_value = 1e9
#         for c in candi:
#             min_value = min(min_value, abs(hy - chicken[c][0]) + abs(hx - chicken[c][1]))
#         cnt += min_value
#     ret = min(ret, cnt)        
# print(ret)


ret = 1e9
total = 0
for h_y,h_x in house:
    for candidate in candidates:
        diff = 1e9
        for idx in candidate:
            c_y, c_x = chicken[idx]
            diff = min(diff, abs(h_y-c_y) + abs(h_x-c_x))
        
        total += diff
        print(f'{diff=}')
        
    print(f'{total=}')
ret = min(ret, total)
print(ret)   

# ret = 1e9
# for candidate in candidates:
#     for idx in candidate:
#         c_y, c_x = chicken[idx]
#         diff = 0
#         print(f'{house=}')
#         for h_y, h_x in house:
#             print(f'{abs(c_y-h_y) + abs(c_x-h_x)=}')
#             diff += abs(c_y-h_y) + abs(c_x-h_x)
#         ret = min(ret, diff)
#         print(f'{diff=}, {ret=}')
# print(ret)