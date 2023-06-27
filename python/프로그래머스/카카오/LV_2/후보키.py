def is_candidate(subset,relation,row,col):
    for col_a in range(col-1):
        for col_b in range(col_a+1,col):
            key_a = []
            key_b = []
            for r in range(row):
                if (subset & (1 << r)):
                    key_a.append(relation[col_a][r])
                    key_b.append(relation[col_b][r])
            if key_a == key_b:
                return False
    return True

def solution(relation):
    row = len(relation[0])
    col = len(relation)
    candidate = []
    for subset in range(1, 1 << row):
        if is_candidate(subset,relation,row,col):
            candidate.append(subset)
            
    # 최소성을 만족시켜라...
    # 비트키준 오름차순 정렬
    candidate.sort(key=lambda x : bin(x).count('1'))
    
    answer = 0
    while candidate:
        n = candidate.pop(0)
        answer += 1
        candidate = [x for x in candidate if (n & x) != n]
    return answer