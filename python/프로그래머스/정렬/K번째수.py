def solution(array, commands):
    ret = []
    for i, j, k in commands:
        part = sorted(array[i-1:j])
        # part.sort()
        ret.append(part[k-1])
    return ret