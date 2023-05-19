from collections import deque

def testPrint(field):
    for i in range(20):
        for j in range(20):
            print(field[i][j], end=' ')
        print()

def solution(rectangle, characterX, characterY, itemX, itemY):
    characterX *= 2 
    characterY *= 2
    itemX *= 2
    itemY *= 2
    
    answer = 0
    MAX = 102  # 두배로 늘리기 때문에 최대 102
    # 테투리 그리기
    field = [[8] * MAX for _ in range(MAX)] # 8은 맨처음 땅
    for rec in rectangle:
        x1,y1,x2,y2 = map(lambda x: x * 2, rec)
        for i in range(y1, y2 + 1):
            for j in range(x1, x2 + 1):
                if x1 < j < x2 and y1 < i < y2:
                    field[i][j] = 0
                elif field[i][j] != 0:
                    field[i][j] = 1
                    
    testPrint(field)
    # 길 찾기 (최단거리는 BFS)
    q = deque()
    q.append([characterY, characterX])
    visited = [[0] * MAX for _ in range(MAX)]
    visited[characterY][characterX] = 1
    dy,dx = [-1,0,1,0], [0,1,0,-1]
    while q:
        y,x = q.popleft()
        if x == itemX and y == itemY:
            answer = visited[y][x] // 2
            break
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if visited[ny][nx] == 0 and field[ny][nx] == 1:
                q.append([ny,nx])
                visited[ny][nx] = visited[y][x] + 1
    
    return answer

print("ret = ",solution(
    [[1,1,7,4],[3,2,5,5],[4,3,6,9],[2,6,8,8]],
    1,	3,	7,	8
         ))
