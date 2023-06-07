def makeTwochar(word):
    splited = []
    start = 0
    for end in range(1,len(word)):
        ch = ''.join(word[start:end+1])
        start = end
        is_alpha = True
        # 영어를 제외한 철자2개는 버린다
        for i in ch:
            if not i.isalpha():
                is_alpha = False
        if is_alpha:
            splited.append(ch)
    return splited

def makeResult(a,b):
    # J(A, B)는 두 집합의 교집합(일치하는 데이터) 크기를 두 집합의 합집합(모든 데이터) 크기로 나눈 값
    ret = 1 # 공집합 = 아무것도 일치하지 않을 때 = 1
    if b != 0 or a != 0: # 한개라도 0이라면 나눗셈이 성립하지 않음
        ret = b / a
    ret = int(ret * 65536)
    return ret

def solution(str1, str2):
    # 대소문자 비교 x
    str1 = list(str1.lower())
    str2 = list(str2.lower())
    
    # 2개의 char로 변경
    splited_str1 = makeTwochar(str1)
    splited_str2 = makeTwochar(str2)
    
    # 교집합 A ∩ B는 원소 "1"을 min(3, 5)인 3개, 합집합 A ∪ B는 원소 "1"을 max(3, 5)인 5개 가지게 된다.
    a1 = splited_str1[:]
    a2 = splited_str1[:]
    for i in splited_str2:
        if i not in a1:
            a2.append(i)
        else:
            a1.remove(i)
    
    b = []
    for i in splited_str2:
        if i in splited_str1:
            splited_str1.remove(i)
            b.append(i)
    
    ret = makeResult(len(a2),len(b))
    return ret