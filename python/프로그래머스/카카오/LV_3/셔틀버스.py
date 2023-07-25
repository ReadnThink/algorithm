from collections import deque

def get_time(timetable):
    time = deque()
    for t in timetable:
        t = t.split(':')
        time.append(int(t[0])*60 + int(t[1]))
    return time
def int_to_str(t):
    HH = str(t // 60).zfill(2)
    MM = str(t % 60).zfill(2)
    return HH + ':' + MM

def solution(n, t, m, timetable):
    timetable.sort()
    timetable = get_time(timetable)
    shuttle = [540 + (i*t) for i in range(n)] # 셔틀 출발시간
    # print(timetable)
    # print(shuttle)
    answer = 0
    for departure in shuttle:
        onboard_cnt = 0
        last = -1
        while timetable and timetable[0] <= departure and onboard_cnt < m:
            onboard_cnt +=1
            last = timetable.popleft()
        
        if onboard_cnt == m:
            answer = last-1
        else:
            answer = departure
    
    return int_to_str(answer)