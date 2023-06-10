import sys
import copy
sys.setrecursionlimit(10000000)
input = sys.stdin.readline

n,m = map(int,input().split())
words = [list(input().strip()) for _ in range(n)]
words_set = set()
count = -1 # 동일한 문자열이 존재하지 않는 입력만 주어짐 즉 처음은 무조건 1
isFindStr = False
arr = []
for i in range(m):
    temp = ''
    for j in range(1,n):
        temp += words[j][i]
    arr.append(temp)
# for i in range(m):
#     print(arr[i])

for i in range(n):
    for j in range(m):
        temp = arr[j][i:]
        if temp in words_set:
            isFindStr = True
            break
        else:
            words_set.add(temp)
    if isFindStr:
        break
    count += 1

print(count)