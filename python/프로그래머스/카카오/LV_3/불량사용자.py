check = set()

def is_same(uid, bid):
    if len(uid) != len(bid):
        return False
    for i, ch in enumerate(uid):
        if bid[i] == "*":
            continue
        elif ch != bid[i]:
            return False
    return True

def get_bit(arr):
    bit, offset = 0, 0
    for i, val in enumerate(arr):
        if val:
            bit += (1 << offset)
        offset += 1
    return bit

def dfs(user_id, banned_id, bid_idx, convertable, selected):
    global check
    if bid_idx == len(banned_id):
        check.add(get_bit(selected))
        return
        
    for uid_idx, uid in enumerate(user_id):
        if not convertable[bid_idx][uid_idx]:
            continue
        elif selected[uid_idx]:
            continue
        selected[uid_idx] = True
        dfs(user_id, banned_id, bid_idx + 1, convertable, selected)
        selected[uid_idx] = False

def solution(user_id, banned_id):
    global check
    convertable = []
    for bid in banned_id:
        convertable.append([is_same(uid,bid) for uid in user_id])
    print(f'{convertable=}')
    
    dfs(user_id, banned_id, 0, convertable, [False for _ in range(len(user_id))])
    return len(check)