def unique_check(temp):
    length = len(temp)
    set_length = len(set(temp))
    # print(length, set_length)
    return length == set_length

def is_unique(relation, subset, col, row):
    
    temp = []
    for r in relation:
        tempA = []
        for c in range(col):
            if subset & (1 << c):
                tempA.append(r[c])
        temp.append(''.join(tempA))
        
    # print('temp! = ',temp)
    if unique_check(temp) == False:
        return False
        
    return True
                

def solution(relation):
    col, row = len(relation[0]), len(relation)
    candidates = []
    for subset in range(1, 1 << col):
        if is_unique(relation,subset,col,row):
            candidates.append(subset)
            
    # print(candidates)
    # 정렬이 되어야 하지만, 이미 정렬된 순으로 들어와있다.
    # candidates.sort(key=lambda x : bin(x).count('1'))
    # print(candidates)
    
    answer = 0
    while candidates:
        n = candidates.pop(0)
        # print(n, bin(n))
        answer += 1
        candidates = [x for x in candidates if (n & x) != n]
        # print('남은 후보들 : ', candidates)
        
    return answer