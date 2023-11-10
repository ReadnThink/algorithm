import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

DIRTY = 0
WALL = 1
CLEAN = 2
dy = [-1,0,1,0]
dx = [0,1,0,-1]

def printTest(arr):
    for i in range(n):
        print(arr[i])
    print()

def go(y,x,d):
    global ret
    cur = room[y][x]
    if cur == DIRTY:
        room[y][x] = CLEAN
        ret += 1
    is_block = True
    
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        if 0 <= ny < n and 0 <= nx < m:
            if room[ny][nx] == DIRTY:
                is_block = False
    
    if not is_block:
        for i in range(4):
            nd = ((d+3)-i)%4
            ny = y+dy[nd]
            nx = x+dx[nd]
            if 0 <= ny < n and 0 <= nx < m:
                if room[ny][nx] == DIRTY:
                    go(ny,nx,nd)
    if is_block:
        by = y + dy[(d+2) % 4]
        bx = x + dx[(d+2) % 4]
        if 0 <= by < n and 0 <= bx < m and room[by][bx] != WALL: 
            go(by,bx,d)
        else:
            print(ret)
            # print(f'{y,x,d=}')
            # printTest(room)
            exit(0)

ret = 0
n,m = map(int, input().split())
y,x,d = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(n)]
go(y,x,d)