def parse(s):
    cnt = 0
    for idx, ch in enumerate(s):
        cnt = cnt+1 if ch == '(' else cnt-1
        if cnt == 0:
            return s[:idx+1], s[idx+1:]
            
def is_valid(s):
    cnt = 0
    for ch in s:
        cnt = cnt+1 if ch == '(' else cnt-1
        if cnt < 0:
            return False
    return True

def reverse(s):
    rev = []
    for ch in s:
        rev.append( ')' if ch == '(' else '(')
    return ''.join(rev)

def solution(p):
    if p == '':
        return ''
    u,v = parse(p)
    if is_valid(u):
        return u + solution(v)
    else:
        # print(f"u: {u}, v:{v}")
        return '(' + solution(v) + ')' + reverse(u[1:-1])
    

p = "(()())()"
p1 = ")("
p2 = "()))((()"
print(solution(p))
print(solution(p1))
print(solution(p2))