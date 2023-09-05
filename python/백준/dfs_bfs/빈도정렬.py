import sys

N,C = map(int, input().split())

nums = list(map(int, input().split()))

dic = {}

for n in nums:
    dic[n] = dic.get(n, 0) + 1

# print(dic)    
dic = dict(sorted(dic.items(), key=lambda x : -x[1]))
# print(dic)
for key, value in dic.items():
    for _ in range(value):
        print(key, end=' ')