def solution(s):
    length = len(s)
    answer = len(s)
    # 중복이되는것을 자른다.
    for interval in range(1,length // 2 + 1): # 문자열을 자르는 길이 (절반까지만 돌면 된다.)
        start = 0
        z_zip = 0
        cnt = 1
        while start+interval <= length:
            word = s[start:start+interval]
            # print(f"intv:{interval} start:{start} word:{word}")
            while word == s[start+interval*cnt: start+interval*(cnt+1)]:
                cnt += 1
            
            if cnt > 1:
                z_zip += len(str(cnt))
            z_zip += len(word)
            start += interval*cnt
            cnt = 1
            
        z_zip += len(s[start:])
        answer = min(answer, z_zip)
        
    return answer