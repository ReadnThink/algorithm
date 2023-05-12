def solution(phone_book):
    # 1. Hash Map을 만든다. -> Dict
    hash_map = {}
    for num in phone_book:
        hash_map[num] = 1
    
    # 2. 접두어가 Hash Map에 존재하는지 확인한다.
    for phone_num in phone_book:
        jubdoo = ''
        for num in phone_num:
            jubdoo += num
            # 3. 접두어를 찾아야 한다. (기존 번호와 같은 경우 제외)
            if jubdoo in hash_map and jubdoo != phone_num:
                return False
            
    answer = True
    return answer