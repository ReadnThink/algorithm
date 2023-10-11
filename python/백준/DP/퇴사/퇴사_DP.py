import sys
sys.setrecursionlimit(10000000)
n = int(input())
days = [list(map(int,input().split())) for _ in range(n)]
answer = 0

def dfs(day, sum, n, days):
    global answer    
    if day > n:
        return
    if day == n:
        answer = max(answer,sum)
        return
    dfs(day + days[day][0], sum + days[day][1], n, days)
    dfs(day + 1, sum, n, days)


dfs(0,0,n,days)
print(answer)