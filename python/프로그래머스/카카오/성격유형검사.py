def solution(survey, choices):
    scores = {
              1: 3, 
              2: 2,
              3: 1, 
              4: 0, 
              5: 1, 
              6: 2,
              7: 3
             }
    table = {
        'R':0, 'T':0,
        'C':0, 'F':0,
        'J':0, 'M':0,
        'A':0, 'N':0
    }
    # 가장 높은 유형의 점수 찾기 -> 사전순
    # 유형별로 테이블의 점수를 올려야 한다.
    # survey, choices
    for i,choice in enumerate(choices):
        if choice == 0 :
            continue
        pick = 1
        if choice < 4:
            pick = 0
        # print(survey[i][pick])
        table[survey[i][pick]] += scores[choice]

        
    answer = ''
    if table['R'] >= table['T']:
        answer += 'R'
    elif table['R'] < table['T']:
        answer += 'T'
    if table['C'] >= table['F']:
        answer += 'C'
    elif table['C'] < table['F']:
        answer += 'F'
    if table['J'] >= table['M']:
        answer += 'J'
    elif table['J'] < table['M']:
        answer += 'M'
    if table['A'] >= table['N']:
        answer += 'A'
    elif table['A'] < table['N']:
        answer += 'N'
        
    return answer