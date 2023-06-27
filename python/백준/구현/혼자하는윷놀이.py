import sys
input = sys.stdin.readline



def move(yuk):
    move = 0
    if yuk == 0 or yuk == 4:
        if yuk == 0:
            move += 5
        if yuk == 4:
            move += 4
    if yuk == 1: # 한칸
        move += 1
    if yuk == 2: # 두칸
        move += 2
    if yuk == 3: # 세칸
        move += 3
    return move

course = 0
location = 0
isWin = False
for i in range(10):
    yuk = input().strip().count('0')
    location += move(yuk)    
    # print(location, course, isWin)
    if course == 0:
        if location == 5:
            course = 1
            location = 0
        elif location == 10:
            course = 2
            location = 0
        elif location >= 21:
            isWin = True
    elif course == 1:
        if location == 3:
            course = 2
            location = 0
        elif location >= 12:
            isWin = True
    elif course == 2:
        if location >= 7:
            isWin = True
    elif course == 3:
        if location >= 4:
            isWin = True
            
if isWin:
    print('WIN')
else:
    print('LOSE')