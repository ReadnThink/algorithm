from collections import deque
def solution(queue1, queue2):
    # 두개의 queue 중에 큰 queue를 골라 다른 큐에 넣는 그리디 문제
    # sum의 연산이 O(n)이여서 sum을 O(1)이 되도록 만드는 문제 
    q1 = deque(queue1)
    q2 = deque(queue2)
    sum_q1 = sum(q1)
    sum_q2 = sum(q2)
    mid = (sum_q1 + sum_q2) // 2
    
    print(mid)
    answer = 0
    while True:
        if sum_q1 == mid and sum_q2 == mid:
            break 
            
        if mid < sum_q1:
            out = q1.popleft()
            sum_q1 -= out
            q2.append(out)
            sum_q2 += out
            
        elif mid < sum_q2:
            out = q2.popleft()
            sum_q2 -= out
            q1.append(out)
            sum_q1 += out
            
        answer += 1
        if answer == 250000:
            answer = -1
            break
        # break
    # print(q1,q2)
    return answer