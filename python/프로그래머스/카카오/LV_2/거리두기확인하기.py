from collections import deque

dy = [1,-1,0,0]
dx = [0,0,1,-1]

def dfs(y,x,places,depth,visited):
    ret = 0
    visited[y][x] = True
    if depth == 2:
        return 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= 5 or nx >= 5 or visited[ny][nx] or places[ny][nx] == 'X':
            continue
        if places[ny][nx] == 'P':
            return 1
        ret += dfs(ny,nx,places,depth+1,visited)
    return ret

def solve(places):
    visited = [[False]*5 for _ in range(5)]
    for i in range(len(places)):
        for j in range(len(places[i])):
            if places[i][j] == 'P':
                if dfs(i,j,places,0,visited):
                    return 0
    return 1

def solution(places):
    answer = []
    for i in range(len(places)):
        answer.append(solve(places[i]))
    return answer