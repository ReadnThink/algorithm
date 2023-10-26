import sys
input = sys.stdin.readline

def solve(A,B):
    A.sort()
    B.sort()
    ret, b_idx = 0,0
    for i in A:
        while b_idx < len(B) and i > B[b_idx]:
            b_idx += 1
        ret += b_idx
    print(ret)

t = int(input())
while t:
    n,m = map(int, input().split())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    solve(A,B)
    t -= 1