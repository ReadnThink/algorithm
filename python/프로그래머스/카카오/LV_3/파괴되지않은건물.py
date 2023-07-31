def go(board,s):
    t,sy, sx, ey, ex, degree = s[0],s[1],s[2],s[3],s[4], s[5]
    
    for i in range(sy,ey+1):
        for j in range(sx,ex+1):
            if t == 1:
                board[i][j] -= degree
            elif t == 2:
                board[i][j] += degree
    # for i in range(len(board)):
    #     print(board[i])
    # print()
    return board

def count(board):
    result = 0
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] > 0:
                result += 1
    return result

def solution(board, skill):
    for s in skill:
        board = go(board,s)        
    answer = count(board)
    return answer