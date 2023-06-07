def solution(cacheSize, cities):
    LRU = []
    answer = 0
    
    for data in cities:
        data = data.lower()
        # 데이터가 있다면 Cache Hit
        if data in LRU:
            out = LRU.pop(LRU.index(data))
            LRU.insert(0,data)
            answer += 1            
        else: # 데이터가 없다면 Cache Miss
            if cacheSize > 0:
                # 데이터를 넣을 수 있다면 넣는다.
                if len(LRU) < cacheSize:
                    LRU.insert(0,data)
                else: # 데이터를 넣을 수 없다면 가장 오래전에 참조된 데이터를 지운다
                    LRU.pop()
                    LRU.insert(0,data)
                answer += 5
            else:
                answer += 5
        # print(LRU, answer)    
    return answer