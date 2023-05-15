# [5,6,7] -> 5를 바라볼때 cnt가 계속 늘어나야 한다. -> while문?
def solution(citations):
    ret = 0
    n = len(citations)
    citations.sort()
    print(citations)
    
    for i in range(n):
        rest = n - i
        # print("rest = ", rest,"ret = ", ret,"citation = ", citations[i])
        while ret < citations[i] and ret < rest:
            ret += 1
            # print("ret ", ret)
    
    return ret