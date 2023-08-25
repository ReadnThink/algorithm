def solution(s):
    length = len(s)
    answer = length
    for interval in range(1,(length // 2)+1):
        zip_s = 0
        start = 0
        while start + interval <= length:
            repeat = 1
            sub = s[start: start + interval]
            while sub == s[start+(interval*repeat): start+(interval*(repeat+1))]:
                repeat += 1
            if repeat > 1:
                zip_s += len(str(repeat))
            zip_s += len(sub)
            start += interval * repeat
            
        zip_s += len(s[start:])
        # print(f"{zip_s=}, {interval=}")
        answer = min(answer, zip_s)
    
    return answer