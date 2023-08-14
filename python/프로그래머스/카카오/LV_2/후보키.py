def is_candidate(subset,relation,row,col):
    for col_a in range(col-1):
        for col_b in range(col_a+1,col):
            key_a = []
            key_b = []
            for r in range(row):
                if (subset & (1 << r)):
                    key_a.append(relation[col_a][r])
                    key_b.append(relation[col_b][r])
            print(f'{key_a=},{key_b=}')
            if key_a == key_b:
                print('같은 튜플입니다!')
                return False
    return True

def solution(relation):
    row = len(relation[0])
    col = len(relation)
    candidate = []
    for subset in range(1, 1 << row):
        print()
        if is_candidate(subset,relation,row,col):
            print('추가되었습니다.',subset)
            candidate.append(subset)
            
    # 최소성을 만족시켜라...
    # 비트키준 오름차순 정렬
    print('최소성을 만족시켜라...')
    candidate.sort(key=lambda x : bin(x).count('1'))
    print(candidate)
    answer = 0
    while candidate:
        n = candidate.pop(0)
        print(n, bin(n))
        answer += 1
        candidate = [x for x in candidate if (n & x) != n]
        print('남은 후보들',candidate)
    return answer