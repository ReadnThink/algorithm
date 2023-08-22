def split_file(file):
    HEAD = NUMBER = TAIL = ''
    for i in range(len(file)):
        if file[i].isnumeric():
            HEAD = file[:i]
            NUMBER = file[i:]
            break
    for i in range(len(NUMBER)):
        if not NUMBER[i].isnumeric():
            TAIL = NUMBER[i:]
            NUMBER = NUMBER[:i]
            break
    return HEAD,NUMBER,TAIL

def solution(files):
    
    splited_file = []
    for file in files:
        splited_file.append(split_file(file))
    # print(splited_file)
    
    splited_file.sort(key=lambda x : (x[0].upper(), int(x[1])))
    
    answer = []
    for file in splited_file:
        answer.append(''.join(file))
    return answer