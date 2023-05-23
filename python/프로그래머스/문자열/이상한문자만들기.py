def solution(s):
    words = s.split(' ')
    
    answer = ''
    for word in words:
        word = list(word)
        for i in range(len(word)):
            if i % 2 == 0:
                word[i] = word[i].upper()
            else:
                word[i] = word[i].lower()
        answer += ''.join(word)
        answer += ' '
    
    print(words) # 내용 안바뀜
    print(answer)
    return answer[:-1]