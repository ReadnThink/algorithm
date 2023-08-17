import sys
input = sys.stdin.readline

n,m = map(int,input().split())
arr = list(map(int,input().split()))

def check(mid):
    if mx > mid:
        return False
    size = 0
    cnt = 0
    
    for n in arr:
        # print(f'{size=}, {mid=}')
        size += n
        if size > mid:
            cnt += 1
            size = n
        elif size == mid:
            cnt += 1
            size = 0
        
    if size:
        cnt += 1
    # print(cnt, m, cnt <= m)
    return cnt <= m    


l, r, ret, mx = 1, sum(arr), sys.maxsize, max(arr)
while l <= r:
    mid = (l+r) // 2
    
    if check(mid):
        r = mid - 1
        ret = min(ret, mid)
    else:
        l = mid + 1

print(ret)