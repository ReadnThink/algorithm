import heapq
def solution(jobs):
    ret, now, i = 0,0,0
    start = -1
    heap = []
    
    while i < len(jobs):
        
        # 작업 수행중 들어오는 다른 작업을 넣는 과정
        # 처음에는 0초만 들어오고 now가 늘어나면서 들어올 수 있는 범위가 바뀐다.
        for job in jobs:
            if start < job[0] <= now:
                heapq.heappush(heap, (job[1], job[0]))
        print(heap)
        print(ret)
        # 하나의 작업 수행
        if len(heap) > 0:
            cur = heapq.heappop(heap)
            start = now
            now += cur[0]
            ret += (now - cur[1])
            i += 1
        # 작업할 것이 없다면 다음 작업시간까지 범위를 늘린다. 
        else:
            now +=1
      
        
            
    return ret // len(jobs)
    
