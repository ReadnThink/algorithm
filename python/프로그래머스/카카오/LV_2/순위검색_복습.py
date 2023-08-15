from bisect import bisect_left

def solution(info, query):
    dic = {}
    for string in info:
        w = string.split()
        for subset in range(1 << 4):
            q = []
            for i in range(4):
                if (subset & 1 << i):
                    q.append(w[i])
            
            sub_q = ''.join(q)
            if sub_q in dic:
                dic[sub_q].append(w[4])
            else:
                dic[sub_q] = [w[4]]
    
    sorted_dic = {key: sorted(map(int, values)) for key, values in dic.items()}
    
    answer = []
    for string in query:
        w = string.split()
        score = int(w.pop())
        q = ''.join(w).replace('-', '').replace('and','')
        
        # 리스트에 값이 없는 경우 null을 반환한다.
        if q not in sorted_dic:
            sorted_dic[q] = [0]
        
        answer.append(len(sorted_dic[q]) - bisect_left(sorted_dic[q], score))
        
    return answer