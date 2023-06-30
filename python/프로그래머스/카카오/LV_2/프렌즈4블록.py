dy = [0,0,1,1]
dx = [0,1,0,1]

def printArr(arr):
    print('----------------test!')
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            print(arr[i][j], end='')
        print()

def check(y,x,cur,board):
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        
        if ny < 0 or nx < 0 or ny >= len(board) or nx >= len(board[0]):
            return False
        
        if board[ny][nx] != cur:
            return False
    return True

def pop(y,x,board):
    pop_cnt = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        
        if ny < 0 or nx < 0 or ny >= len(board) or nx >= len(board[0]):
            continue
        
        if board[ny][nx] != ' ':
            board[ny][nx] = ' '
            pop_cnt += 1
    return pop_cnt

def gravity(y,x,arr):
    for i in range(y-2, -1, -1):
        for j in range(x):
            temp_i = i
            while temp_i < y-1 and arr[temp_i+1][j] == ' ': # swap
                arr[temp_i+1][j], arr[temp_i][j] = arr[temp_i][j], arr[temp_i+1][j]
                temp_i += 1

def solution(m, n, board):
    answer = 0
    # list로 변환
    for i in range(m):
        board[i] = list(board[i])
    # 블록이 안사라질때까지 반복하기
    while True:
        pop_list = []
        
        # 터질 위치 확인
        for i in range(m):
            for j in range(n):
                if board[i][j] != ' ' and check(i,j,board[i][j],board):
                    pop_list.append([i,j])
        
        # 터트리기
        for y,x in pop_list:
            answer += pop(y,x,board)
        
        # 내리기
        gravity(m,n,board)
        # printArr(board)
        
        if len(pop_list) == 0:
            break
    
    return answer