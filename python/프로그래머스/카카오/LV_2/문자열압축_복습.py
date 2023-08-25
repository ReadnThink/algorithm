def solution(s):
    n = len(s)
    answer = n
    
    for interval in range(1, n//2+1):
        zip_s = ''
        start = 0
        while start+interval <= n:
            repeat = 1
            sub = s[start: start+interval]
            while sub == s[start+(interval*repeat): start+(interval*(repeat+1))]:
                repeat += 1
            if repeat > 1:
                zip_s += str(repeat)
            zip_s += sub
            start += interval * repeat
        
        zip_s += s[start:]
        print(f'{interval = }, {zip_s = }')
        
        answer = min(answer, len(zip_s))    
    return answer