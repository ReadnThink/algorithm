import sys
from collections import deque
input = sys.stdin.readline

s = list(input().strip())
t = list(input().strip())
is_possible = False
while True:
    if len(s) > len(t):
        break
    s.append('A')
    if ''.join(s) == ''.join(t):
        is_possible = True
        break
    s.reverse()
    s.append('B')
    if s == t:
        is_possible = True
        break
if is_possible:
    print(1)
else:
    print(0)