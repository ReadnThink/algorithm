def dayToInt(days):
    day = 0
    for i in range(len(days)):
        if i == 0:
            days[i] = days[i][2:]
            day += int(days[i]) * 12 * 28
        if i == 1:
            day += int(days[i]) * 28
        if i == 2:
            day += int(days[i])
    return day

def solution(today, terms, privacies):
    days = today.split('.')
    # today 가공
    day = dayToInt(days)
    
    # terms 가공
    term = {}
    for i in range(len(terms)):
        s = terms[i].split(' ')
        term[s[0]] = int(s[1]) * 28
    
    # print(day)
    # print(term)
    
    # privacies 가공 후 유효기간 diff 계산
    answer = []
    for i in range(len(privacies)):
        privaciy = privacies[i].split(' ')
        p_day = dayToInt(privaciy[0].split('.')) + term[privaciy[1]]
        # print(p_day)
        if day >= p_day:
            answer.append(i+1)
    return answer