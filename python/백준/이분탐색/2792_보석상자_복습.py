import sys
input = sys.stdin.readline

def check(mid):
    if mx > mid:
        return False
    cnt = 0
    sum = 0
    
    for v in arr:
        if sum + v <= mid:
            sum += v
        else:
            sum = v
            cnt += 1
    if sum:
        cnt += 1
    # print(mid, ' cnt = ', cnt,' sum = ', sum)
    return cnt <= M

N,M = list(map(int, input().split()))
arr = list(map(int, input().split()))
left,right = 1, sys.maxsize
ret,mx = sys.maxsize,max(arr)

while left <= right:
    mid = (left+right) // 2
    
    if check(mid):
        ret = min(ret, mid)
        right = mid - 1
        
    else:
        left = mid + 1
print(ret)