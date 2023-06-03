import sys
from collections import deque
input = sys.stdin.readline
global k
n,k = map(int, input().split())
arr = list(map(int, input().split()))
belt = deque(arr)

# broken이 없어도 되는 이유는? belt가 0이면 어차피 내구도가 0이기 때문인가?
# 처음에 belt가 0이 중복으로 들어올때 체크하면 중복으로 k가 -될줄 알았는데 어차피 조건에서
# belt > 0 으로 거르고 있으니 broken을 필요가 없다.
#broken = deque([False]*(n*2))

robot = deque([False]*n)

ret = 0
def print_all(memo):
    print(memo)
    print("blet = ", belt)
    print("robot = ", robot)
    print()
    
def move_belt(m):
    out = m.pop()
    m.appendleft(out)
    
def robot_move():
    global k
    for i in range(len(robot)-1, 0, -1):
        if robot[i] == False and robot[i-1] == True and belt[i] > 0:
            robot[i] = True
            robot[i-1] = False
            belt[i] -= 1
            if belt[i] <= 0:
                k -= 1
    
def down_robot():
    if robot[n-1] == True:
        robot[n-1] = False
        
def take_robot():
    global k
    if belt[0] > 0:
        belt[0] -= 1
        robot[0] = True
        if belt[0] <= 0:
            k -= 1

while True:
    ret += 1
    move_belt(belt)
    move_belt(robot)
    # print_all("belt move")
    down_robot()
    # print_all("donw")
    robot_move()
    # print_all("robot move")
    down_robot()
    # print_all("down")
    if k <= 0:
        break
    # 로봇 올리기
    take_robot()
    # print_all("take robot")
    if k <= 0:
        break
# print(n,k,arr)
print(ret)
