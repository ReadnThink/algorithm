from collections import Counter

def solution(participant, completion):
    # participant의 counter를 구한다.
    part_counter = Counter(participant)
    # completion의 counter를 구한다.
    comp_counter = Counter(completion)
    
    print(part_counter)
    print(comp_counter)
    print(part_counter - comp_counter)
    answer = part_counter - comp_counter
    # 둘의 차를 구하고, Key를 읽어온다.
    print(answer.keys())
    print(list(answer.keys())[0])
    
    return list(answer.keys())[0]