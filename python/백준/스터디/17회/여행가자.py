n = int(input())
m = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
route = list(map(int, input().split()))
parent = [0]*(n)
# print("route = ", route)
# print("arr = ", arr)


# 초기화
for i in range(n):
    parent[i] = i

def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    x = find(a)
    y = find(b)
    if x > y:
        parent[x] = y
    else:
        parent[y] = x

for i in range(n):
    for j in range(n):
        if arr[i][j] == 0: continue
        # print(i,j)
        union(i,j)

connect = find(int(route[0]-1))

flag = True
for i in range(len(route)):
    if connect != find(route[i]-1):
        flag = False
        
if flag:
    print("YES")
else:
    print("NO")