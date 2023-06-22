from itertools import combinations
from bisect import bisect_left

def solution(info, query):
    info_dict = {}
    
    for i in range(len(info)):
        infol = info[i].split(' ')
        key = infol[:-1] # 점수 제외 정보
        # key.append('-')
        value = int(infol[-1]) # 점수
        
        for j in range(5): # 정보로 만들 수 있는 모든 조합 dic로 생성
            for c in combinations(key,j):
                tmp = ''.join(c)
                # print(tmp)
                if tmp in info_dict:
                    info_dict[tmp].append(value)
                else:
                    info_dict[tmp] = [value]
                # info_dict[tmp].append(info_dict.get(tmp, list).append(int(value)))
    # print(info_dict)  
    # print()
    for k in info_dict:
        info_dict[k].sort() # 이분탐색을 위한 value들을 정렬
    # print(info_dict)  

    answer = []
    for q in query:
        q = q.split()
        value = int(q[-1])
        q = q[0]+q[2]+q[4]+q[6]
        key = ''.join(q).replace('-', '')
        # print(key,value)
        
        if key in info_dict: # query의 key가 존재한다면
            scores = info_dict[key]
            if scores:
                enter = bisect_left(scores, value)
                answer.append(len(scores)-enter)
        else:
            answer.append(0)
    return answer