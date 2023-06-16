import math
def replace_step(m):
    return m.replace("C#", "c").replace("D#", "d").replace("F#", "f").replace("G#", "g").replace("A#", "a")

def get_diff(start,end):
    return (int(end[:2])*60 + int(end[3:])) - (int(start[:2])*60 + int(start[3:]))

def solution(m, musicinfos):
    answer = None
    max_play_time = 0
    
    m = replace_step(m)
    
    for musicinfo in musicinfos:
        start_time, end_time, name, melody = musicinfo.split(",")
        play_time = get_diff(start_time,end_time)
         
        melody = replace_step(melody)
        melody_repeated_cnt = math.ceil(play_time/len(melody))
        melody_played = (melody*melody_repeated_cnt)[:play_time]
        # print(melody_played, melody_repeated_cnt, play_time/len(melody))
        
        if m in melody_played and play_time > max_play_time:
            answer = name
            max_play_time = play_time
            
    if answer is None:
        return "(None)"
    return answer