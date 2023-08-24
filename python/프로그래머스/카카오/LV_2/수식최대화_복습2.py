import re

def perm(depth, arr, visited):
    if depth == 3:
        operaters.append(arr[:])
        return
    
    for i,op in enumerate(['+', '-', '*']):
        if visited[i]:
            continue
        visited[i]=True
        arr.append(op)
        perm(depth+1,arr,visited)
        arr.pop()
        visited[i]=False

def curculate(op, t1, t2):
    ret = 0
    if op == '+':
        ret = int(t1) + int(t2)
    if op == '-':
        ret = int(t1) - int(t2)
    if op == '*':
        ret = int(t1) * int(t2)
    return ret        
    
        
operaters = []
def solution(expression):
    perm(0,[], [False]*3)
    expression = re.split('([-*+])', expression)
    max_result = 0
    for operater in operaters:
        candidate = expression[:]
        for op in operater:
            while op in candidate:
                idx = candidate.index(op)
                s = curculate(op,candidate[idx-1], candidate[idx+1])
                candidate[idx-1] = str(s)
                
                del candidate[idx:idx+2]
            
        max_result = max(max_result, abs(int(candidate[0])))
    
    return max_result