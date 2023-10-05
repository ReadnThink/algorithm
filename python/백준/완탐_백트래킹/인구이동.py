import sys
input = sys.stdin.readline
from queue import PriorityQueue
from collections import deque
sys.setrecursionlimit(1000000)
import copy

dy = [1,-1,0,0]
dx = [0,0,1,-1]
def debug(arr):
    for i in range(n):
        for j in range(n):
            print(arr[i][j], end=' ')
        print()
    print()

def dfs(y,x,visited, contries):
    contries.append([y,x])
    sum = board[y][x]
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        
        if 0 <= ny < n and 0 <= nx < n:
            if visited[ny][nx]:
                continue
            if l <= abs(board[y][x] - board[ny][nx]) <= r:
                visited[ny][nx] = True
                sum += dfs(ny,nx,visited, contries)
    return sum
    
    
n,l,r = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
ret = 0
while True:
    is_move = False
    visited = [[False]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if visited[i][j]:
                continue
            visited[i][j] = True
            contries = []
            sum = dfs(i,j,visited, contries)
            
            if len(contries) > 1:
                # ret +=1 을 여기서 하면 map을 한번 탐색시 연합이 여러군데 있을 수 있어 인구인동의 날을 카운트 하는것이 아니다.
                # 즉, 연합나라가 생긴 것을 카운트 하는 것이된다.
                # 따라서 is_move가 없을때 count를 올려야 한다.
                for y,x in contries:
                    board[y][x] = sum // len(contries)
                    is_move = True
    # debug(board)
    if not is_move:
        break
    ret += 1
print(ret)
    