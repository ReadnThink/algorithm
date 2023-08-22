bases = '0123456789ABCDEF'
def convert(n,base):
    ret = ''
    while n:
        ret += bases[n%base]
        n //= base
    if ret == '':
        ret = '0'
    return ret[::-1]
    

def solution(n, t, m, p):
    
    limit = t*m
    candidates = []
    for i in range(limit):
        make = convert(i,n)
        for ch in make:
            candidates.append(ch)
        
    candidates = ''.join(candidates)
    # print(candidates)
    
    answer = []
    order = p
    for i,ch in enumerate(candidates):
        if len(answer)==t:
            break
        if i+1 == order:
            answer.append(ch)
            order += m
            
    return ''.join(answer)