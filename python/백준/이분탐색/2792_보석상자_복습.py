import sys
input = sys.stdin.readline

N,M = list(map(int, input().split()))
arr = [int(input()) for _ in range(M)]

def check(mid):
    cnt = 0
    for bosuk in arr:
        cnt += bosuk // mid
        if bosuk % mid:
            cnt += 1
    print(f'{cnt=}')
    return cnt <= N


l , r = 1, max(arr)
ret = 1000000000
while(l <= r):
    mid = (l + r) // 2
    print(f'{mid=}')
    if check(mid):
        ret = min(ret, mid)
        r = mid - 1
    else:
        l = mid + 1

print(ret)