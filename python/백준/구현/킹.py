import sys
input = sys.stdin.readline

ROW = {'A':0,'B':1,'C':2,'D':3,'E':4,'F':5,'G':6,'H':7}
ROW_BACK = {0:'A',1:'B',2:'C',3:'D',4:'E',5:'F',6:'G',7:'H'}
board = [[0 for _ in range(8)] for _ in range(8)]
dir_dict = {'R':(0,1),'L':(0,-1),'B':(-1,0),'T':(1,0),'RT':(1,1),'LT':(1,-1),'RB':(-1,1),'LB':(-1,-1)}
info = input().strip().split()
king = list(info[0])
rock = list(info[1])
king_x, king_y, rock_x, rock_y = ROW[king[0]], int(king[1]), ROW[rock[0]], int(rock[1])
# print(king_y, king_x, rock_y, rock_x)
n = int(info[2])

for _ in range(n):
    command = input().strip()
    # move(king_y, king_x, rock_y, rock_x,command)
    dir = dir_dict[command]
    ky = king_y + dir[0]
    kx = king_x + dir[1]
    if ky < 1 or kx < 0 or ky >= 9 or kx >= 8:
        pass
        # print('범위가 넘어갔습니다.',ky,kx,command)
    else:
        if ky == rock_y and kx == rock_x:
            # print('돌과 위치가 같습니다. 돌을 밀어내세요')
            ry = rock_y + dir[0]
            rx = rock_x + dir[1]
            if ry < 1 or rx < 0 or ry >= 9 or rx >= 8:
                pass
                # print('범위가 넘어갔습니다.',ky,kx,command)
            else:
                king_y, king_x = ky, kx
                rock_y, rock_x = ry, rx
        else:
            king_y, king_x = ky, kx
    

# print(king_y, king_x, rock_y, rock_x)
king_location = ROW_BACK[king_x]+str(king_y)
rock_location = ROW_BACK[rock_x]+str(rock_y)
print(king_location)
print(rock_location)
    