def solution(msg):
    
    dic = {chr(ord('A')+i):i+1 for i in range(26)}
    
    msg.upper()
    answer = []
    cnt = 27
    i = 0
    while i < len(msg):
        end = i + 1
        
        while end < len(msg) and msg[i:end] in dic:
            end += 1
        
        answer.append(dic[msg[i:end-1]])
        dic[msg[i:end]] = cnt
        cnt += 1
        
        i = end-1
        
    return answer

print(solution("KAKAO") == [11, 1, 27, 15])
print(solution("TOBEORNOTTOBEORTOBEORNOT") == [20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34])
print(solution("ABABABABABABABAB") == [1, 2, 27, 29, 28, 31, 30]) 