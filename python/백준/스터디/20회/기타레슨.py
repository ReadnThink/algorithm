import sys
input = sys.stdin.readline

n,m = map(int,input().split())
arr = list(map(int,input().split()))
l,r,s,mx = 1,sum(arr),sum(arr), max(arr)
ret = sys.maxsize

def check(mid):
    if mid < mx:
        return False
    cnt = 0
    sum = 0
    # print('mid==========',mid)
    for i in arr:
        sum += i
        if sum > mid:
            cnt += 1
            sum = i
        elif sum == mid:
            cnt += 1
            sum = 0
        # print(sum)
    if sum > 0:
        cnt +=1
    # print('cnt = ',cnt)
    if cnt <= m:
        return True
    return False

while l <= r:
    mid = (l+r) // 2
    if check(mid):
        # print('가능!', mid)
        r = mid - 1
        ret = mid
    else:
        # print('불가능!', mid)
        l = mid + 1
print(ret)