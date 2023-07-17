import heapq

def solution(stones, k):
    h = []
    answer =  200_000_001
    for i in range(k-1):
        heapq.heappush(h, [-stones[i], i])
    
    for i in range(k-1, len(stones)):
        heapq.heappush(h, [-stones[i], i])
        print('--------insert = ', stones[i])
        print('heap = ', h, '\nmaxIndex = ', h[0][1], 'i-k =',i-k)
        while h[0][1] <= i-k:
            # heapq.heappop(h)
            print('pop!',heapq.heappop(h), 'i-k =',i-k)
        print('min = ',-h[0][0], h[0][1])
        answer = min(answer, -h[0][0])
    
    return answer