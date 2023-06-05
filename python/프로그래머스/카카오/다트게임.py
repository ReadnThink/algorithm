def solution(dartResult):
    scores = []
    i = 0
    while i < len(dartResult):
        if dartResult[i].isdigit():
            score = 0
            j = i
            while(dartResult[j].isdigit()):
                temp = int(dartResult[j])
                if temp == 0:
                    score *= 10
                else :
                    score += temp
                j += 1
            i = j-1
            # print(score)
            scores.append(score)
                          
        if dartResult[i] == 'D':
            scores[-1] **= 2
        elif dartResult[i] == 'T':
            scores[-1] **= 3
        if dartResult[i] == '*':
            scores[-1] *= 2
            if len(scores) >= 2:
                scores[-2] *= 2
        elif dartResult[i] == '#':
            scores[-1] *= -1
        i += 1
            
    # print(scores)
    return sum(scores)

print(solution('1S2D*3T'))
print(solution("1D2S#10S"))
print(solution("1D2S0T"))