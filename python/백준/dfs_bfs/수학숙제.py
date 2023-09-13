import sys

n = int(input())

ret = []
for i in range(n):
    arr = input()
    num = ''
    for w in arr:
        if w.isnumeric():
            num += w
        elif len(num) > 0:
            ret.append(int(num))
            num = ''
    if len(num) > 0:
        ret.append(int(num))
    
ret.sort()
for i in ret:
    print(i)
        