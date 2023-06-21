PER = []
PERCENT = [40, 30, 20, 10]

def make_per(depth, arr, n):
    if depth == n:
        PER.append(arr[:])
        return
    
    for i in PERCENT:
        arr.append(i)
        make_per(depth+1, arr, n)
        arr.pop()
        
def get_sale(price, percent):
    return price - ((price * percent) // 100)
        
def solution(users, emoticons):
    answer = [0,0] # 플러스 가입 수, 이모티콘 매출 액
    result = []
    make_per(0,[],len(emoticons)) #할인률 만들기
    
    for percents in PER: # 할인률 중복순열
        total_pay, plus_join = 0,0
        for rate, price in users: # 유저마다 이모티콘 할인률에 따른 가입여부를 확인해야 하니 유저기준으로 for문 작성
            pay = 0
            for i, emo in enumerate(emoticons):
                if percents[i] >= rate: # 유저의 최대 할인률보다 할인률이 크다면 구입가능
                    pay += get_sale(emo, percents[i])
            
            if pay >= price: # 이모티콘 구매 취소 플러스 가입
                plus_join += 1
            else: # 플러스 가입하지 않는 경우
                total_pay += pay
        
        # 유저마다 할인률에 따른 정보를 업데이트 시켜줘야 함
        # print(f"{answer = } {plus_join, total_pay}")
        result.append([plus_join,total_pay])
    result.sort(key=lambda x : (-x[0], -x[1]))
    return result[0]