import sys
input = sys.stdin.readline
n = int(input())
words = [input().strip().upper() for _ in range(n)]

simbol = {'M': 1000, 'CM': 900, 'D': 500, 'CD': 400, 'C': 100, 'XC': 90, 
          'L': 50, 'XL': 40, 'X': 10, 'IX': 9, 'V': 5, 'IV': 4, 'I': 1}
times = {'M': 10_001, 'CM': 1, 'D': 1, 'CD': 1, 'C': 3, 'XC': 1, 
         'L': 1, 'XL': 1, 'X': 3, 'IX': 1, 'V': 1, 'IV': 1, 'I': 3}
third = ['I', 'X', 'C']
two = ['IV', 'IX', 'XL', 'XC', 'CD', 'CM']

def check(number, cur_word):
    #기호 I, X, C은 연속해서 세 번까지만 사용할 수 있다.
    # 3번 이상
    if cur_word in third:
        time = number.count(cur_word)
        if time > 3:
            return False
        if time <= 3:
            for i in range(len(number)-1, len(number)-1-time, -1):
                if number[i] != cur_word:
                    return False
    #IV와 IX는 같이 쓸 수 없으며 XL과 XC, CD와 CM 또한 같이 쓸 수 없다.
    elif cur_word in two:
        for time in times:
            if time in two and times[time] == 0:
                return False
                
    return True
    

for i in range(n):
    # print(words[i])
    find_idx = -1
    cur = 0
    sum = 0
    number = ''
    for cur_word in simbol:
        # 큰 수가 항상 앞에와야 한다.
        while not words[i][cur:].find(cur_word) == -1:
            find_idx = words[i].find(cur_word)
            
            # 붙어있는것 처리
            if not check(number, cur_word):
                continue
            # 카운트도 세줘야 한다.
            if not times[cur_word]:
                continue
            times[cur_word] -= 1
            
            # print(find_idx, cur, cur_word)
            
            # 인덱스 최신화
            if cur < find_idx:
                cur = find_idx
            
            words[i] = words[i][:find_idx] + '.' + words[i][find_idx+1:]
            sum += simbol[cur_word]
            number += cur_word
            break
    print(sum)
    # print(number)

 