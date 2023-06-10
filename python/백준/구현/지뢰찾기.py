import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
n = int(input())

booms = [input().strip() for _ in range(n)]
played = [input().strip() for _ in range(n)]
result = [['.' for _ in range(n)] for _ in range(n)]

dy = [1,1,-1,-1,1,-1,0,0]
dx = [1,-1,1,-1,0,0,1,-1]

def dfs(y,x):
    ret = 0
    for i in range(8):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= n or nx >= n:
            continue
        if booms[ny][nx] == '*':
            ret += 1
    return ret

is_fail = False
for i in range(n):
    for j in range(n):
        if played[i][j] == 'x':
            if booms[i][j] == '*':
                is_fail = True
            result[i][j] = str(dfs(i,j))

if is_fail:
    for i in range(n):
        for j in range(n):
            if booms[i][j] == '*':
                result[i][j] = '*'

for i in range(n):
    print(''.join(result[i]))
    # print(result[i])