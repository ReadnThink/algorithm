import sys
input = sys.stdin.readline

n = int(input())

A,B = 1, 1
high = 1

while True:
    B += 4*high
    A += B
    
    if A > n:
        break
    high += 1

print(high)