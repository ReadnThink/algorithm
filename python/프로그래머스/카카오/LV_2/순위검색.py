from collections import defaultdict
from bisect import bisect_left

def make_subset(info):
    # info_dict = defaultdict(list)
    info_dict = {}
    for inf in info:
        user_info = inf.split()
        score = int(user_info[4])
        # print(user_info)
    
        for subset in range(1 << 4): # 모든 부분집합에 score를 저장
            key = []
            for idx in range(4):
                if (subset & 1 << idx) == 0:
                    continue
                key.append(user_info[idx])
            key = ''.join(key)
            # defaultdict 사용시
            # info_dict[key].append(score) 
            if key not in info_dict:
                info_dict[key] = [score]
            else:
                info_dict[key].append(score)
    return info_dict

def parse_key(query):
    # q = q.replace('-','').replace('and','').split()
    # score = int(q[-1])
    # key = ''.join(q[:-1])
    
    q = query.split()
    key = q[0]+q[2]+q[4]+q[6]
    score = int(q[7])
    
    key = key.replace('-','')
    return key,score
    

def solution(info, query):
    info_dict = make_subset(info)
    # print(info_dict)
    
    # 정렬
    for key,value in info_dict.items():
        value.sort()
        
    # 쿼리에 맞는 조건 answer에 저장
    answer = []
    for q in query:
        key,score = parse_key(q)
        if key in info_dict: # 입력하는 query에서 key가 없는경우가 들어올 수 있다.
            values = info_dict[key]
            answer.append(len(values) - bisect_left(values, score))
        else:
            answer.append(0)
    return answer