def solution(s):
    
    n = len(s) // 2 + 1
    for interval in range(1,n):
        start = 0
        cnt = 1
        z_zip = ''
        print('interval = ', interval , "   ------------------")
        while start+interval <= len(s):
            sub = s[start:interval]
            print(sub)
            while sub == s[start+interval:start+(interval*2)]:
                cnt += 1
                print('intarval : ',s[start+interval:start+(interval*2)])
                start += interval
            
            if cnt > 1:
                z_zip += str(cnt)
            z_zip += sub
            
            if s[start:interval] == s[start:interval]:
                start += 1
            
            
        print('----------')
    answer = 0
    return answer

print(solution("aabbaccc"))