import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == 0:
        break
    rules = [list(input().split()) for _ in range(n)]
    from_ = input().strip()
    to = input().strip()
    
    is_possible = False
    change_cnt = 0
    while not is_possible:
        for rule in rules:
            # 있으면 바꾼다
            is_change = False
            while from_.find(rule[0]) >= 0:
                is_change = True
                from_ = from_.replace(rule[0], rule[1], 1)
            if is_change:
                change_cnt += 1 
            if from_ == to:
                is_possible = True
    print(change_cnt)
    break
    
    # 한 규칙(αi, βi)을 여러 번 사용해도 되고, 사용하지 않아도 된다.
    