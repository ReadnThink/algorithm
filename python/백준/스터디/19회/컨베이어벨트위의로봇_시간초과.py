import sys
from collections import deque
input = sys.stdin.readline

n,k = map(int, input().split())
belt = list(map(int,input().split()))
broken = [False for _ in range(n*2)]
on_board = [False for _ in range(n)]
q = deque(belt)

def move_belt(belt):
    last = belt[-1]
    for i in range(len(belt)-1, -1,-1):
        belt[i] = belt[i-1]
    belt[0] = last
ret = 0

def can_move(belt, on_board, i):
    # 내구도가 1이상이고, 로봇이 없고
    if belt[i] > 0 and on_board[i] == False:
        if on_board[i-1] == True: #  로봇 있으면
            return True
    return False

while True:
    ret += 1
    # print("회전 전----------")
    # print("belt = ",belt)
    # print("내구도 ",broken)
    # print("탑승 ",on_board)
    # print("k = ",k)
    
    # 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    # print("----------회전 후----------")
    move_belt(belt)
    move_belt(broken)
    move_belt(on_board)
    # print("belt = ",belt)
    # print("탑승 ",on_board)
    # print("내구도 ",broken)
    
    # 로봇이 이동 후 내려야하는 자리라면, 바로 내려야 한다.
    if on_board[n-1] == True:
        on_board[n-1] = False
    # 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
    for i in range(len(on_board)-1, 0, -1):
        if can_move(belt, on_board, i):
            # 내구도 감소
            belt[i] -= 1
            # 내구도 0이면 k 감소
            if belt[i] <= 0 and broken[i] == False:
                broken[i] = True
                # print("로봇이 이동할떄")
                k -= 1
            # 로봇 이동
            on_board[i] = True
            on_board[i-1] = False
            # 로봇이 이동 후 내려야하는 자리라면, 바로 내려야 한다.
            if i == n-1:
                on_board[i] = False
    if k <= 0:
        break
    # 이동
    # 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.    
    if belt[0] != 0 and on_board[0] == False and broken[0] == False:
        belt[0] -= 1
        on_board[0] = True
    if belt[0] == 0 and broken[0] == False:
        broken[0] = True
        # print("로봇이 올라갈때")
        k -= 1
    
    # 로봇은 N-1번 인덱스에서 즉시내림
    if on_board[n-1] == True:
        on_board[n-1] = False
    # 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
    if k <= 0:
        break
print(ret)