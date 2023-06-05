def solution(N, stages):
    # 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
    answer = []
    ret = []
    on_stage_players = len(stages)
    
    for i in range(1,N+1):
        if on_stage_players == 0:
            answer.append((0,i))
            continue
        
        not_clear_players = stages.count(i)
        fail = not_clear_players / on_stage_players
                
        answer.append((fail, i))
        
        on_stage_players -= not_clear_players
    
    answer.sort(key=lambda x : x[0], reverse=True)
    for i in range(N):
        ret.append(answer[i][1])
    return ret

