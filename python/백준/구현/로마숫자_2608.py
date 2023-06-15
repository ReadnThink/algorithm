import sys
from collections import deque
input = sys.stdin.readline

op = {'M': 1000, 'CM': 900, 'D': 500, 'CD': 400, 'C': 100, 'XC': 90, 
      'L': 50, 'XL': 40, 'X': 10, 'IX': 9, 'V': 5, 'IV': 4, 'I': 1}

first = input().strip()
second = input().strip()

#  I, X, C, M은 연속해서 세 번 나머지 한번
 
def get_num(str):
    s = 0
    need_last_count = False
    limit = len(str)
    end = 0
    while end < limit:
        # end가 str의 길이와같지 않다면 2개까지 확인해보기
        if not end == limit-1:
            if str[end:end+2] in op:
                if end == limit:
                    # 마지막 전에 2개를 세었다면 하나 더 카운트 해야함
                    need_last_count = True
                s += op[str[end:end+2]]
                end += 2
                continue
        if str[end] in op:
            s += op[str[end]]
            end += 1
        
    if need_last_count:
        print(str[-1])
        s += op[str[-1]]
    return s

def get_roma(s):
    times = {'M': 3, 'CM': 1, 'D': 1, 'CD': 1, 'C': 3, 'XC': 1, 
      'L': 1, 'XL': 1, 'X': 3, 'IX': 1, 'V': 1, 'IV': 1, 'I': 3}    
    word = []
    for t in times:
        value = op.get(t) # 뺄 숫자
        limit = times[t]
        while limit and s >= value:
            s -= value
            times[t] -= 1
            word.append(t)
    return ''.join(word)


s = get_num(first) + get_num(second)
word = get_roma(s)
print(s)
print(word)