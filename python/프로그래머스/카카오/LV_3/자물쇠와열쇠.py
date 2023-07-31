def printArr(temp):
    for i in range(len(temp)):
        for j in range(len(temp[0])):
            print('%3d' % temp[i][j], end='')
        print()
    print()

def expend_arr(lock,length, lock_len, key_len):
    temp = [[-1 for _ in range(length)] for _ in range(length)]
    hole = 0
    for i in range(lock_len):
        for j in range(lock_len):
            temp[i+key_len-1][j+key_len-1] = lock[i][j]
            if lock[i][j] == 0:
                hole += 1
    return temp, hole

def rotate(arr, key_len):
    temp = [[0 for _ in range(key_len)] for _ in range(key_len)]
    
    for i in range(key_len):
        for j in range(key_len):
            # temp[i][j] = arr[j][key_len-1-i] // 시계 반대방향
            temp[j][key_len-1-i] = arr[i][j]
    # printArr(temp)
    return temp
    

def solution(key, lock):
    lock_len,key_len = len(lock), len(key)
    length = lock_len + ((key_len-1) * 2)
    
    # arr 확장
    lock, HOLE = expend_arr(lock,length, lock_len, key_len)
    # printArr(lock)
    
    keys = []
    keys.append(key)
    for i in range(3):
        keys.append(rotate(keys[-1], key_len))
    
    # 대조해보기
    for i in range(lock_len + key_len - 1):
        for j in range(lock_len + key_len - 1):
            for d in range(4):
                find_hole = 0
                is_conflit = False
                for key_i in range(key_len):
                    for key_j in range(key_len):
                        if lock[i+key_i][j+key_j] == -1:
                            continue
                        if keys[d][key_i][key_j] == lock[i+key_i][j+key_j]:
                            is_conflit = True
                            continue
                        if keys[d][key_i][key_j] == 1 and lock[i+key_i][j+key_j] == 0:
                            find_hole += 1
                
                if find_hole == HOLE and is_conflit == False:
                    # print(HOLE, find_hole, d)
                    # print(i,j)
                    return True
                    
    return False