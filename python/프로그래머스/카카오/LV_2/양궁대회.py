from copy import deepcopy

diff = 0
candidate = []

def compare(origin, new):
    for idx in range(10, -1, -1):
        if origin[idx] > new[idx]:
            return False
        elif origin[idx] < new[idx]:
            return True

# score는 점수 -> 10, 9, 8, 7 ,6 ... 순으로 내려갈것임 
def dfs(shoot_cnt, score, info, ryan):
    global candidate, diff
    if shoot_cnt == 0 or score == 0: # 최종 점수를 계산
        if score == 0:
            ryan[10] = shoot_cnt
        # 최종 점수 계산
        total_a, total_r = 0,0
        for i in range(11):
            if info[i] == 0 and ryan[i] == 0:
                continue
            if info[i] >= ryan[i]:
                total_a += (10 - i)
            else:
                total_r += (10 - i)
                
        if total_r > total_a:
            if diff < (total_r - total_a):
                candidate = deepcopy(ryan)
                diff = (total_r - total_a)
            elif diff == (total_r - total_a) and compare(candidate, ryan):
                candidate = deepcopy(ryan)
        return
    
    idx = 10 - score
    # 해당 score를 ryan이 흭득하는 경우
    if shoot_cnt > info[idx]:
        temp = deepcopy(ryan)
        temp[idx] = info[idx] + 1 # 어피치보다 한발 더 쏜다
        dfs(shoot_cnt - info[idx] -1, score-1, info, temp)
    # 해당 score를 ryan이 포기하는 경우
    temp = deepcopy(ryan)
    dfs(shoot_cnt, score-1, info, temp)
    
def solution(n, info):
    global candidate
    ryan = [0 for _ in range(11)]
    dfs(n,10,info,ryan)
    return candidate if candidate else [-1]