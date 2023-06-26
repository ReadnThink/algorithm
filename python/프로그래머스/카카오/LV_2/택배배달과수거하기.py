def printArr(arr):
    for i in arr:
        print(i, end=' ')
    print()

def calcul(give, box):
    diff = box - give
    if diff >= 0:
        return True
    else:
        return False
    
def solution(cap, n, deliveries, pickups):
    answer = 0
    
    while True:
        turn = -1
        turn1 = -1
        # 택배 배달하기
        box = cap
        for i in range(n-1, -1, -1):
            give = deliveries[i]
            if box == 0:
                break
            if give > 0 and turn == -1:
                turn = i + 1
            if give > 0:
                if calcul(give,box):
                    deliveries[i] -= give
                    box -= give
                else:
                    deliveries[i] -= box
                    box = 0
                    
        if turn == -1:
            break 
        
        # 택배 수거하기
        box = cap
        for i in range(turn-1, -1, -1):
            take = pickups[i]
            if box == 0:
                break
            if take > 0 and turn == -1:
                turn = i + 1
            if take > 0:
                if calcul(take,box):
                    pickups[i] -= take
                    box -= take
                else:
                    pickups[i] -= box
                    box = 0
        # printArr(deliveries)
        # printArr(pickups)
        
        move = max(turn, turn1) * 2
        answer += move
    return answer