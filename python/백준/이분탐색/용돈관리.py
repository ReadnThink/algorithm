import sys
input = sys.stdin.readline

n,m = map(int,input().split())
prices = [int(input()) for _ in range(n)]
left, right,mx = 0, sum(prices), max(prices)
ret = 0

def check(mid):
    if mx > mid:
        return False
    # print()
    
    cnt = 0
    k = mid
    for price in prices:
        # print(k)
        if k - price < 0:
            cnt += 1
            k = mid
        k -= price
    
    if k != mid:
        cnt += 1
    # print()
    # print('check ', cnt, mid)
    return cnt <= m

while left <= right:
    mid = (left+right)//2
    if check(mid):
        # print('성공 : ',mid)
        right = mid - 1
        ret = mid
    else:
        # print('실패 : ',mid)
        left = mid + 1

print(ret)