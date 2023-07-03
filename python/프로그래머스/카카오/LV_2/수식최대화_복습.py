import re

candidates = []
def reculsive(depth,temp,visited):
    if depth == 3:
        candidates.append(temp[:])
        return
    for idx,value in enumerate(['+', '-', '*']):
        if visited[idx]:
            continue
        temp.append(value)
        visited[idx] = True
        reculsive(depth+1,temp,visited)
        visited[idx] = False
        temp.pop()
    
def calcaulate(front,back, operator):
    ret = -1
    if operator == '-':
        ret = front - back
    if operator == '+':
        ret = front + back
    if operator == '*':
        ret = front * back
    return ret
    

def solution(expression):
    expression = re.split('([-+*])', expression)
    reculsive(0,[],[False for _ in range(3)])

    answer = 0
    for operator in candidates:
        temp = expression.copy()
        for op in operator:
            while op in temp:
                idx = temp.index(op)
                cal_num = calcaulate(int(temp[idx-1]), int(temp[idx+1]), temp[idx])
                temp[idx-1] = cal_num
                del temp[idx:idx+2]
                
        # print(temp)
        answer = max(answer, abs(int(temp[0])))
    # print(candidates)
    return answer