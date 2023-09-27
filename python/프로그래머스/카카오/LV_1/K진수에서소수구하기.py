import math
bases = '0123456789ABCDFG'
def convert(num, n):
    ret = []
    while num:
        ret.append(bases[num%n])
        num //= n
    return ''.join(ret[::-1])

def is_prime(n):
    if n == 1 or n == 0:
        return False
    if n == 2:
        return True
    for i in range(3, int(math.sqrt(n))+1, 2):
        if n % i == 0:
            return False
    return True

    
def solution(n, k):
    n = convert(n,k)
    nums = n.split('0')
    # 00의 경우 스플리에서 빈 문자열이 만들어 지기 때문에 '' if num으로 유효한 num만 list로 변환ㄹ
    nums = [int(num) for num in nums if num] 
    
    answer = 0
    for num in nums:
        if is_prime(num):
            answer += 1
    return answer