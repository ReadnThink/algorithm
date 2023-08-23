# 반드시 처음부터 재생되며 음악 길이보다 재생된 시간이 길 때는 음악이 끊김 없이 처음부터 반복해서 재생된다.
    # 00:00를 넘겨서까지 재생되는 일은 없다.
    
def get_played_time(t, t1):
    A = int(t[:2])*60 + int(t[3:])
    B = int(t1[:2])*60 + int(t1[3:])
    if t[:2] != '00' and t1[:2] == '00':
        B = int('23')*60 + int('59')
    return B-A

def get_size(time, song):
    return time // song

def make_target_lower(m):
    return m.replace('C#','c').replace('D#','d').replace('F#','f').replace('G#','g').replace('A#','a')

def is_correct(m,song,played_time):
    return m in song[:played_time+1]

def solution(m, musicinfos):
    m = make_target_lower(m)

    candidates = []
    for music in musicinfos:
        music = music.split(',')
        played_time = get_played_time(music[0], music[1])
        song = make_target_lower(music[3])
        size = get_size(played_time, len(song))
        
        song *= size+1
        print(f'{song=}, {m=}')
        if is_correct(m,song, played_time):
            candidates.append([played_time, music[2]])
        
    # 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다.
    # 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
    candidates.sort(key=lambda x : -x[0])
    if candidates:
        answer = candidates[0][1]
    else:
        answer = '(None)'
    return answer