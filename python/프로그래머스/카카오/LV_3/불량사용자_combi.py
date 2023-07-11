def combi(temp, number, calculate):
    global result
    if len(temp) == len(calculate):
        # print(f'{temp = }')
        temp = set(temp)
        if temp not in result:
            result.append(temp)
        return
    else:
        for j in range(len(calculate[number])):
            if calculate[number][j] not in temp:
                temp.append(calculate[number][j])
                combi(temp, number+1, calculate)
                temp.pop()
result = []
def solution(user_id, banned_id):
    global result
    calculate = []
    for ban in banned_id:
        possible=[]
        for user in user_id:
            if len(ban) != len(user):
                continue
            else:
                count = 0
                for i in range(len(ban)):
                    if user[i] == ban[i] or ban[i] == '*':
                        count+=1
                if count == len(ban):
                    possible.append(user)
                    
        # print(f'{possible=}')
        calculate.append(possible)
        
    # print(f'{calculate=}')
    combi([], 0, calculate)
    # print(f'{result=}')
    return len(result)