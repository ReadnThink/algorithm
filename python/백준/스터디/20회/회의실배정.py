import sys
input = sys.stdin.readline

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]

# 정렬이 0번째도 알아서 되는 줄 알았다...
arr.sort(key=lambda x:(x[1],x[0]))
cur = arr[0][1]
ret = 1
for i in range(1,n):
    # 회의가 끝나자 마자 시작할 수 있기때문에 <=로 해줘야 한다.
    if cur <= arr[i][0]:
        cur = arr[i][1]
        ret += 1
    # print(arr[i], cur)
print(ret)
    