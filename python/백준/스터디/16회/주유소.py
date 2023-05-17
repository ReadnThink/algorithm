n = int(input())
km = list(map(int,input().split()))
station = list(map(int,input().split()))
min_cost = station[0]
# 처음에는 무조건 주유를 한다
ret = station[0] * km[0]

for i in range(1,len(km)):
    if station[i] >= min_cost:
        ret += min_cost * km[i]
    else:
        min_cost = station[i]
        ret += station[i] * km[i]
        
print(ret)