import sys
from collections import deque
input = sys.stdin.readline

str = input().strip()
boom = input().strip()
stk = []
boom_len = len(boom)
for s in str:
    stk.append(s)
    if len(stk) >= boom_len:
        if ''.join(stk[len(stk)-boom_len:]) == boom:
            for i in boom:
                stk.pop()
    
if len(stk) == 0:
    print('FRULA')
else:
    print(''.join(stk))
