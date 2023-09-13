import sys

def convertToInt(time):
    t = time.split(':')
    return (int(t[0])*60) + int(t[1])

def convertToStr(time):
    HH = time // 60
    MM = time % 60
    return str(HH).zfill(2) + ':' + str(MM).zfill(2)

N = int(input())
scores = [list(input().split()) for _ in range(N)]
scoare_a,scoare_b,A,B = 0,0,0,0

prev = 0
for score in scores:
    team = int(score[0])
    time = convertToInt(score[1])

    if A > B:
        scoare_a += time-prev
    elif A < B:
        scoare_b += time-prev
    
    if team == 1:
        A += 1
    else:
        B += 1
    prev = time

if A > B:
    scoare_a += convertToInt('48:00')-prev
elif A < B:
    scoare_b += convertToInt('48:00')-prev

print(convertToStr(scoare_a))
print(convertToStr(scoare_b))