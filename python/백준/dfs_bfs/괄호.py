import sys

n = int(input())

for _ in range(n):
    arr = input().strip()
    
    stk = []
    
    is_vps = True
    for ch in arr:
        if ch == '(':
            stk.append(ch)
        else:
            if stk:
                stk.pop()
            else:
                is_vps = False
                break
    
    if stk:
        is_vps = False
    
    if is_vps:
        print('YES')
    else:
        print('NO')