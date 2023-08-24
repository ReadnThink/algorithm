from collections import deque

dy = [-1,0,1,0]
dx = [0,1,0,-1]
def bfs(place, y, x):
    # print('p 진입', y,x)
    visited = [[False for _ in range(5)] for _ in range(5)]
    q = deque()
    q.append([y,x,0])
    
    while q:
        cy, cx, cnt = q.popleft()
        # print(cy,cx,cnt)
        visited[cy][cx] = True
        
        if cnt == 2:
            # print("cnt = ", cnt, cy, cx)
            continue
        
        for i in range(4):
            ny = cy+dy[i]
            nx = cx+dx[i]
            
            if 0 <= ny < 5 and 0 <= nx < 5:
                if visited[ny][nx] == True:
                    continue
                if place[ny][nx] == 'X':
                    continue
                if place[ny][nx] == 'P':
                    # print('맨해튼 거리 x', ny,nx)
                    return False
                
                if place[ny][nx] == 'O':
                    visited[ny][nx] = True
                    q.append([ny,nx,cnt+1])
    
    return True
        
    
    
def solution(places):
    # P는 응시자 ,O는 빈 테이블, X는 파티션
    # 각 대기실 별로 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 담습니다.
    
    answer = []
    N = len(places[0])
    M = len(places[0][0])
    for place in places:
        is_safe = True
        for i in range(N):
            for j in range(M):
                if place[i][j] == 'P':
                    is_safe = bfs(place,i,j)
                if not is_safe:
                        break
            if not is_safe:
                break
        if is_safe:
            # print('-----성공----------')
            answer.append(1)
        else:
            # print('---------------실패------------')
            answer.append(0)
        
    return answer