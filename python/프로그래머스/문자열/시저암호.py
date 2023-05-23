def solution(s, n):
    UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    LOWER = "abcdefghijklmnopqrstuvwxyz"
    
    s = list(s)
    for i in range(len(s)):
        if s[i].isupper():
            s[i] = UPPER[(UPPER.index(s[i]) + n) % 26]
        elif s[i].islower():
            s[i] = LOWER[(LOWER.index(s[i]) + n) % 26]
    
    return ''.join(s)