def solution(n, info):
    # 라이언이 우승하지 못하게 하고싶음
    # 같은 점수를 많이 맞춘사람이 점수 흭득
        # 동점이면 어피치가 가져감
    # 최종점수가 같다면 어피치 우승
    answer = [0] * 11
    tmp = [0] * 11
    maxDiff = 0
    
    for subset in range(1 << 10):
        ryan = 0
        apeach = 0
        cnt = 0
        
        for i in range(10):
            if subset & (1 << i):
                ryan += 10 - i
                tmp[i] = info[i] + 1
                cnt += tmp[i]
            else:
                tmp[i] = 0
                if info[i]:
                    apeach += 10 - i
        
        if cnt > n:
            continue
        
        tmp[10] = n - cnt
        
        if ryan - apeach == maxDiff:
            for i in reversed(range(11)):
                if tmp[i] > answer[i]:
                    maxDiff = ryan - apeach
                    answer = tmp[:]
                    break
                elif tmp[i] < answer[i]:
                    break
            
        if ryan - apeach > maxDiff:
            maxDiff = ryan - apeach
            answer = tmp[:]
    
    if maxDiff == 0:
        answer = [-1]
    
    
    return answer