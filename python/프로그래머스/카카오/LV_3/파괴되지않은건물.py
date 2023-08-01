ATTACK = 1
RECOVER = 2

def solution(board, skill):
    update(board, skill)
    
    answer = 0
    for r in range(len(board)):
        for c in range(len(board[0])):
            if is_not_destroyed(board,r,c):
                answer += 1
    return answer

def is_not_destroyed(board, r, c):
    return board[r][c] > 0

def update(board, skill):
    diff = [[0]*(len(board[0]) + 1) for _ in range(len(board)+1)]
    for type, r1, c1, r2, c2, degree in skill:
        d = -degree if type == ATTACK else degree
        diff[r1][c1] += d
        diff[r1][c2+1] += -d
        diff[r2+1][c1] += -d
        diff[r2+1][c2+1] += d
        
    for r in range(len(board)):
        for c in range(1, len(board[0])):
            diff[r][c] += diff[r][c-1]
                
    for c in range(len(board[0])):
        for r in range(1, len(board)):
            diff[r][c] += diff[r-1][c]
            
    for r in range(len(board)):
        for c in range(len(board[0])):
            board[r][c] += diff[r][c]
    