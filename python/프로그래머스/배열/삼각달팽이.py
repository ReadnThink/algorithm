import sys
sys.setrecursionlimit(1000000)
dy = [1,0,-1,1]
dx = [0,1,-1,0]
cnt = 0
# def dfs(y,x,answer,visited):
#     # print("yx = ",y,x)
#     global cnt
#     cnt += 1
#     answer[y][x] = cnt
#     for i in range(3):
#         ny = y + dy[i]
#         nx = x + dx[i]
#         if ny < 0 or nx < 0 or ny >= len(answer) or nx >= len(answer[0]):
#             continue
#         if visited[ny][nx]:
#             continue
#         visited[ny][nx] = True
#         dfs(ny,nx,answer,visited)
        
def dfs(y,x,answer,visited,d):
    global cnt
    cnt += 1
    answer[y][x] = cnt
    visited[y][x] = True
    # d = 0 아래, 1 오른, 2 위
    if d == 0 and y+1 < len(answer) and visited[y+1][x] == False:
        dfs(y+1,x,answer,visited,d)
    
    d = 1
    if d == 1 and x+1 < len(answer[0]) and visited[y][x+1] == False:
        dfs(y,x+1,answer,visited,d)
    
    d = 2
    if d == 2 and y-1 >= 0 and visited[y-1][x-1] == False:
        if x-1 < 0:
            return
        dfs(y-1,x-1,answer,visited,d)
    
    d = 0
    if d == 0 and y+1 < len(answer) and visited[y+1][x] == False:
        dfs(y+1,x,answer,visited,d)
    
    
def solution(n):
    answer = [[0]*n for _ in range(n)]
    visited = [[False]*n for _ in range(n)]
    # 피라미드형 제외한 곳 True처리
    for i in range(n):
        for j in range(i+1,n):
            visited[i][j] = True
    visited[0][0] = True
    
    # dfs탐색
    dfs(0,0,answer,visited,0)
    
    ret = []
    for i in range(n):
        for j in range(n):
            if answer[i][j] != 0:
                ret.append(answer[i][j])
                
    # test 확인
    # for i in range(n):
    #     print(answer[i])
    return ret