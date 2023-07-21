from collections import deque

dy = [0,0,1,-1]
dx = [1,-1,0,0]

def bfs(board, dir):
    q = deque()
    N = len(board)
    prices = [[int(1e9)] * N for _ in range(N)]
    prices[0][0] = 0
    
    q.append([0,0,0,dir])
    
    while q:
        y,x,cost,d = q.popleft()
        
        for i in range(4):
            ny = y+dy[i]
            nx = x+dx[i]
            
            if ny < 0 or nx < 0 or ny >= N or nx >= N:
                continue
            if board[ny][nx]:
                continue
            
            if i == d:
                ncost = cost+100
            else:
                ncost = cost+600
                
            if ncost < prices[ny][nx]:
                    q.append([ny,nx,ncost,i])
                    prices[ny][nx] = ncost 
                    
    for i in range(N):
        print(prices[i])
    print()
    return prices[N-1][N-1]
def solution(board):
    answer = 0
    
    return min(bfs(board,0),bfs(board,2))