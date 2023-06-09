bases = "0123456789ABCDEF"
def convert(n, to):
    base = ''
    while n:
        base += bases[n%to]
        n //= to
    if base == '':
        base = '0'
    return base[::-1]
    
def solution(n, t, m, p):
    limit = t * m
    ret = []
    for i in range(limit):
        make = convert(i,n)
        for i in make:
            ret.append(i)

    answer = ''
    # print(ret)
    for i in range(1,len(ret)):
        if m == p:
            if i % m == 0:
                answer += ret[i-1]    
        else:
            if i % m == p:
                answer += ret[i-1]
    return answer[:t]