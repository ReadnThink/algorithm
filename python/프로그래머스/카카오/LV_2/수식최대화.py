import re
import itertools
def solution(expression):
    expression = re.split('([-+*])', expression)
    operaters = list(itertools.permutations(['-','+','*'],3))
    ret = []
    for operater in operaters:
        exp = expression[:]
        for op in operater:
            while op in exp:
                idx = exp.index(op)
                number = str(eval(exp[idx-1] + op + exp[idx+1]))
                exp[idx-1] = number
                del exp[idx:idx+2]
                
        ret.append(abs(int(exp[0])))
    ret.sort(reverse=True)
    return ret[0]
