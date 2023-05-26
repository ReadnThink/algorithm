def rotate(y1,x1,y2,x2,grid):
    min_value = len(grid) * len(grid[0])
    left_top = grid[y1][x1]
    # 왼
    for y in range(y1,y2):
        grid[y][x1] = grid[y+1][x1]
        min_value = min(min_value,grid[y][x1])
    # 아
    for x in range(x1,x2):
        grid[y2][x] = grid[y2][x+1]
        min_value = min(min_value,grid[y2][x])
    # 오
    for y in range(y2,y1,-1):
        grid[y][x2] = grid[y-1][x2]
        min_value = min(min_value,grid[y][x2])
    # 위
    for x in range(x2,x1,-1):
        grid[y1][x] = grid[y1][x-1]
        min_value = min(min_value,grid[y1][x])
    grid[y1][x1+1] = left_top
    
    # 마지막에 left_pop은 빼두었으니 꼭 비교를 하고 끝내야 한다.
    return min(left_top,min_value)
    
    
def solution(rows, columns, queries):
    # 행렬 초기화
    grid = [[0]*columns for _ in range(rows)]
    cnt = 1
    for i in range(rows):
        for j in range(columns):
            grid[i][j] = cnt
            cnt += 1
    # 회전
    answer = []
    for q in queries:
        y1,x1,y2,x2 = q[0]-1,q[1]-1,q[2]-1,q[3]-1
        
        min_value = rotate(y1,x1,y2,x2,grid)
        answer.append(min_value)
    return answer