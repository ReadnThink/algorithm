import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
students = [list(map(int, input().split())) for _ in range(n**2)]
grid = [[ 0 for _ in range(n)] for _ in range(n)]
visited = [[ False for _ in range(n)] for _ in range(n)]
dy = [1,-1,0,0]
dx = [0,0,1,-1]

def bfs(y,x,student):
    q = deque()
    q.append([y,x])
    like_student = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= n or nx >= n:
            continue
            empty += 1
        # 좋아하는 학생
        if grid[ny][nx] in student:
            like_student += 1
    # 좋아하는 학생
    # print(like_student)
    return like_student

def bfs_empty(y,x):
    q = deque()
    q.append([y,x])
    empty = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= n or nx >= n:
            continue
        # 비어있는 칸
        if grid[ny][nx] == 0:
            empty += 1
    # 좋아하는 학생, 비어있는 칸
    # print(empty)
    return empty


for s in students:
    likes = []
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 0:
                likes.append([bfs(i,j,s[1:]),i,j])
    
    likes.sort(reverse=True)
    
    
    # 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
    if len(likes) <= 1:
        y = likes[0][1]
        x = likes[0][2]
        grid[y][x] = s[0]
    # 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
    # 1을 만족하는 인접한 칸의 인접한 칸을 확인해야한다.
    max_like = likes[0][0]
    empty = []
    for i in likes:
        if i[0] == max_like:
            y = i[1]
            x = i[2]
            empty.append([bfs_empty(y,x),y,x])
    # 가장 많은칸을 찾기위해 reverse
    empty.sort(reverse=True)
    if len(empty) <= 1:
        y = empty[0][1]
        x = empty[0][2]
        grid[y][x] = s[0]
    else:
        max_empty = empty[0][0]
        emptys = []
        for i in empty:
            if i[0] == max_empty:
                emptys.append([i[1],i[2]])
        # 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로,
        # 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
        emptys.sort()
        # print(emptys)
        grid[emptys[0][0]][emptys[0][1]] = s[0]
    # print(likes)
    # print(empty)
    # print(s)
    # for i in range(n):
    #     print(grid[i])
    # print()

# 학생 만족도 구하기
happy = 0
students.sort()
# print(students)
for i in range(n):
    cnt = 0
    for j in range(n):
        # print(grid[i][j], students[grid[i][j]-1][1:])
        cnt = bfs(i,j,students[grid[i][j]-1][1:])
        if cnt == 1:
            happy += 1
        if cnt == 2:
            happy += 10
        if cnt == 3:
            happy += 100
        if cnt == 4:
            happy += 1000
print(happy)
    