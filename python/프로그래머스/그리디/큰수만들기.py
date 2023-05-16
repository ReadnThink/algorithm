def solution(number, k):
    stk = []
    for i in range(len(number)):
        while stk and stk[-1] < number[i] and k > 0:
            stk.pop()
            k -= 1
        stk.append(number[i])
    if k:
        stk = stk[:-k]
    return ''.join(stk)