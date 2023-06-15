import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
OP = [' ', '+', '-']
def dfs(depth, op,n, permutation):
    if depth == n-1:
        permutation.append(op[:])
        return
    
    for i in range(3):
        op.append(OP[i])
        dfs(depth + 1, op,n, permutation)
        op.pop()
    # 0 만들기
    # 더하거나 뺴거나

def get_result(permutation, n):
    for per in permutation:
        string = []
        for i in range(n-1):
            temp = str(i+1) + per[i]
            string.append(temp)
        # 마지막 더해주기
        string.append(str(n))
        t = ''.join(string).replace(' ', '')
        if eval(t) == 0:
            # print('t =',t)
            print(''.join(string))
            
            
while T:
    n = int(input())
    permutation = []
    dfs(0,[],n, permutation)
    get_result(permutation, n)
    print()
    T -= 1