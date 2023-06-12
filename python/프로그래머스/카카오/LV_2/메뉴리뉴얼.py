global dic
dic = {}

def combi(start, depth, com, order, limit):
    if depth == limit:
        dic[com] = dic.get(com, 0) + 1
        return
    
    for i in range(start, len(order)):
        combi(i+1,depth+1, com+order[i], order, limit)
    
    
def solution(orders, course):
    answer = []
    for i in range(len(orders)):
        orders[i] = list(orders[i])
        orders[i].sort()
    
    for c in course:
        dic.clear()
        for order in orders:
            combi(0,0,'',order, c)
        if not len(dic):
            continue
        
        max_value = max(dic.values())
        if max_value >= 2:
            for v in dic:
                if dic[v] == max_value:
                    answer.append(v)
        
    answer.sort()
    return answer