import sys
from collections import deque
input = sys.stdin.readline

gears = [list(input().strip()) for _ in range(4)]
for i in range(len(gears)):
    gears[i] = deque(gears[i])

k = int(input())
moves = [list(map(int,input().split())) for _ in range(k)]

def get_sum():
    sum = 0
    for i in range(len(gears)):
        # print('12시 방향 = ',i, gears[i][0])
        if gears[i][0] == '1':
            if i == 0:
                sum += 1    
            if i == 1:
                sum += 2
            if i == 2:
                sum += 4    
            if i == 3:
                sum += 8    
    return sum
def move_gear(gears, pick, d, visited):
    if pick == 0:
        # 오른쪽만 탐색
        if gears[pick][2] != gears[pick+1][6] and visited[pick+1] == False:
            visited[pick] = True
            move_gear(gears,pick+1,d^1,visited)
    elif pick == 3:
        # 왼만 탐색
        if gears[pick][6] != gears[pick-1][2] and visited[pick-1] == False:
            visited[pick] = True
            move_gear(gears,pick-1,d^1,visited)
    else :
        if gears[pick][2] != gears[pick+1][6] and visited[pick+1] == False:
            visited[pick] = True
            move_gear(gears,pick+1,d^1,visited)
        if gears[pick][6] != gears[pick-1][2] and visited[pick-1] == False:
            visited[pick] = True
            move_gear(gears,pick-1,d^1,visited)
    
    # print('before')
    # print(gears[pick])
    # print('움직입니다')
    if d == 0:
        # print('반시계방향')
        last = gears[pick].popleft()
        gears[pick].append(last)
    else:
        # print('시계방향')
        first = gears[pick].pop()
        gears[pick].appendleft(first)
    
    # print(gears[pick])
    

for move in moves:
    pick = move[0]-1
    direction = move[1]
    # 부호변경을 하기 위해 방향변경
    if direction == -1:
        direction = 0
        
    visited = [False] * 5
    if direction == 1:
        
        move_gear(gears,pick,direction,visited)
    else:
        
        move_gear(gears,pick,direction,visited)

# for i in range(len(gears)):
    # print(gears[i])        
print(get_sum())
