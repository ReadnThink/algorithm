import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int,input().split()))
x = int(input())

arr.sort()
print(arr)
left,right = 0,n-1
ret = 0
while left < right:
    sum = arr[left] + arr[right]
    
    if sum > x:
        right -= 1
    elif sum < x:
        left += 1
    else:
        ret += 1
        left += 1

print(ret)