def solution(board, moves):
    answer = 0
    stk = []
    n = len(board)
    m = len(board[0])
        
    for move in moves:
        for i in range(n):
            cur = board[i][move-1]
            if cur != 0:
                board[i][move-1] = 0
                if stk and stk[-1] == cur:
                    stk.pop()
                    answer += 2
                else:
                    stk.append(cur)
                break
    return answer