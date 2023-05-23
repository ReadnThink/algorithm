import re
def solution(s):
    answer = []
    a = s.split(',{')
    a.sort(key = len)
    print(a)
    for j in a:
        numbers = re.findall("\d+", j)
        print(numbers)
        for k in numbers:
            if int(k) not in answer:
                answer.append(int(k))
    return answer