def dfs(depth, arr, limit):
    if depth == limit:
        percents.append(arr[:])
        return
    
    for p in [10,20,30,40]:
        arr.append(p)
        dfs(depth+1, arr, limit)
        arr.pop()
        

def discount(price, per):
    return price - (price*per) // 100
        
percents = []
def solution(users, emoticons):
    dfs(0,[], len(emoticons))
    
    candidates = []
    answer = [0,0]
    for per in percents:
        emo_plus = 0
        emo_price = 0
        for user_per, user_money in users:
            total = 0
            for i,emo in enumerate(emoticons):
                if user_per <= per[i]:
                    total += discount(emo, per[i])
            
            if user_money <= total:
                emo_plus += 1
            else:
                emo_price += total
        
        if answer[0] < emo_plus:
            answer[0] = emo_plus
            answer[1] = emo_price
        elif  answer[0] == emo_plus and answer[1] < emo_price:
            answer[1] = emo_price
        
        # candidates.append([emo_plus, emo_price])
                
    # candidates.sort(key=lambda x : (-x[0], -x[1]))
    # answer = [candidates[0][0], candidates[0][1]]
    return answer