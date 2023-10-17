import sys
input = sys.stdin.readline

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]

arr.sort(key=lambda x : x[0])

ret = 0

for arrive, time in arr:
    if ret < arrive:
        ret = arrive
    ret += time

print(ret)