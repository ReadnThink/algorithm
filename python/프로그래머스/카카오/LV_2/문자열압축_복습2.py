def solution(s):
    answer = len(s)
    n = len(s)
    limit = (n//2) + 1
    
    for unit in range(1,limit):
        start = 0
        word = ''
        while start+unit <= n:
            cnt = 1
            w = s[start:start+unit]
            while w == s[start+(unit*cnt):start+(unit*(cnt+1))]:
                cnt += 1
            
            if cnt > 1:
                word += str(cnt)
            word += w
            start += unit*cnt
        word += s[start:]
        # print(unit,word)
        answer = min(answer, len(word))
    return answer

print(solution("aabbaccc"))
print('-'*5)
print(solution("abcabcdede"))