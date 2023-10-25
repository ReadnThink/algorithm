import sys
input = sys.stdin.readline

def check(mid):
    cnt = 0
    for v in arr:
        cnt += v // mid
        if v % mid:
            cnt += 1
    return cnt <= n

n,m = map(int,input().split())
arr = list(int(input().strip()) for _ in range(m))
# 최저값(left)가 0이면 ZeroDivisionErrorr 발생
left, ret, right = 1,0,max(arr)

while left <= right:
    mid = (left+right) // 2
    if check(mid):
        ret = mid
        right = mid-1
    else:
        left = mid+1

print(ret)