import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    cnt = 0
    
    while len(scoville) > 1:
        first = heapq.heappop(scoville)
        if first >= K:
            return cnt
        second = heapq.heappop(scoville)
        # print(first + (second * 2))
        heapq.heappush(scoville,first + (second * 2))
        cnt += 1
    
    rest = heapq.heappop(scoville)
    if rest >= K:
        return cnt
    else:
        return -1