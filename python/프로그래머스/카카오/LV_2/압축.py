def solution(msg):
    msg = msg.upper()
    dic = {}
    alpha = 'A'
    for i in range(26):
        dic[chr(ord(alpha) + i)] = i+1
    # print(dic)
    cnt = 27
    l,r = 0,1
    ret = []
    while l < len(msg):
        # print("begin",msg[l:r])
        while r < len(msg)+1 and msg[l:r] in dic:
            r += 1
        ret.append(dic[msg[l:r-1]])
        # print("ret",msg[l:r])
        dic[msg[l:r]] = cnt
        cnt += 1
        l = r-1
        # print(l,r)
    # print(l,r)
    return ret

print(solution("KAKAO") == [11, 1, 27, 15])
print(solution("TOBEORNOTTOBEORTOBEORNOT") == [20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34])
print(solution("ABABABABABABABAB") == [1, 2, 27, 29, 28, 31, 30]) 