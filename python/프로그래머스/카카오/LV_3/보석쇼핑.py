def search(dic, length, gems):
    start, end = 0, len(gems)-1
    
    while True:
        print(f'{dic[gems[end]] = }')
        dic[gems[end]] = dic.get(gems[end], 0) - 1
        if dic[gems[end]] == 0:
            break
        end -= 1
    while True:
        print(f'{dic[gems[start]] = }')
        dic[gems[start]] = dic.get(gems[start], 0) - 1
        if dic[gems[start]] == 0:
            break
        start += 1
        
    return start+1, end+1

def solution(gems):
    dic = dict()
    for gem in gems:
        dic[gem] = dic.get(gem, 0) + 1
    
    length = len(dic)
    # print(f'{dic = }, {length = }')

    i,j = search(dic,length,gems)
    return [i,j]

