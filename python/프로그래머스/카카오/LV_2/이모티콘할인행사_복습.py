def permutation(depth, emos, temp):
    if depth == len(emos):
        percents.append(temp[:])
        return
    
    for i in [40,30,20,10]:
        temp.append(i)
        permutation(depth+1,emos,temp)
        temp.pop()
        

def get_percent(per, origin):
    return origin - ((origin * per) // 100)
        
percents = []
def solution(users, emoticons):
    permutation(0,emoticons, [])
    answer = [0,0]
    
    for percent in percents:
        emo_total,emo_plus = 0,0
        for user_per, user_limit in users:
            total_price = 0
            
            for i,per in enumerate(percent):
                if user_per <= per:
                    total_price += get_percent(per, emoticons[i])
            
            if user_limit <= total_price:
                emo_plus += 1
            else:
                emo_total += total_price
        
        if answer[0] < emo_plus:
            answer[1] = emo_total
            answer[0] = emo_plus
            
        elif answer[0] == emo_plus:
            if answer[1] < emo_total:
                answer[1] = emo_total
    
    return answer