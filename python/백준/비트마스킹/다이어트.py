import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

# 음식 단백질 리스트가 주어지면 비용을 최소화 할 수 있는 음식만 고르고, 가격과 음식 번호를 오름차순으로 출력하시오. 
# 같은 비용이 여러개라면 사전순으로 가장 빠른것을 출력
n = int(input().strip())
minimum = list(map(int,input().split()))
board = [list(map(int, input().split())) for _ in range(n)]

candidates = []
min_value = 2e9

def check(p,f,t,v):
    return minimum[0] <= p and minimum[1] <= f and minimum[2] <= t and minimum[3] <= v

for i in range(1,1 << n):
    p,f,t,v,sum = 0,0,0,0,0
    foods = []
    for j in range(n):
        if i & (1 << j):
            foods.append(j+1)
            p += board[j][0]
            f += board[j][1]
            t += board[j][2]
            v += board[j][3]
            sum += board[j][4]
    
    if check(p,f,t,v):
        if min_value >= sum:
            min_value = sum
            candidates.append([sum,foods[:]])

# print(candidates)
candidates.sort(key=lambda x : (x[0], x[1]))
# print(candidates)
if min_value == 2e9:
    print(-1)
else:
    result = candidates[0][1]
    price = candidates[0][0]
    print(price)
    print(*result)
        