import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

t,w = map(int, input().split())
dp = [[[-1]*2 for _ in range(31)] for _ in range(t)]
tree = [int(input().strip()) for _ in range(t)]

def go(idx, move, place):
    # 1000개까지 들어오는 idx가 t와 같으면 종료
    if idx == t:
        return 0
    # 더이상 움직일 수 없기때문에 연산하지 않고 종료
    if move < 0:
        return 0
    
    ret = dp[idx][move][place]
    if ret != -1:
        return ret
    
    ret = max(
            go(idx+1, move, place),
            go(idx+1, move-1, place^1)) + (place == tree[idx]-1)
    dp[idx][move][place] = ret
    
    return ret


print(max(go(0,w,0),go(0,w-1,1)))