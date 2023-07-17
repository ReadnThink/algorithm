def solution(gems):
    N, diamond_size = len(gems), len(set(gems))
    candi = []
    start, end = 0,0
    dic = {gems[0]:1}
    while end != N or start != N:
        if len(dic) == diamond_size:
            candi.append([start+1,end+1, end-start])
            dic[gems[start]] -= 1
            if dic[gems[start]] == 0:
                del dic[gems[start]]
            start += 1
        else:
            end += 1
            if end == N:
                break
            dic[gems[end]] = dic.get(gems[end],0) + 1
            
    
        print(dic)
    
        
    candi.sort(key=lambda x : x[2])
    print('result!',candi)
    answer = [candi[0][0],candi[0][1]]
    return answer

# print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
# print(solution(["AA", "AB", "AC", "AA", "AC"]))
# print(solution(["XYZ", "XYZ", "XYZ"]))
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))
