import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
stk = []
ret = [-1]*n

for i in range(n):
    while len(stk) > 0 and arr[stk[-1]] < arr[i]:
        ret[stk[-1]] = arr[i]
        stk.pop()
    stk.append(i)

for r in ret:
    print(r, end=' ')
        



