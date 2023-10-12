import sys
sys.setrecursionlimit(10000000)
n = int(input())
INF = -987654321
days = [list(map(int,input().split())) for _ in range(n)]
answer = 0
cache = [0] * (n+1)

def dfs(day, n, days):
    global answer    
    if day > n:
        return INF
    if day == n:
        return 0
    
    if cache[day] != 0:
        return cache[day]
    
    cache[day] = max(
        dfs(day + days[day][0], n, days) + days[day][1],
        dfs(day + 1, n, days)
    )
    return cache[day]

answer = dfs(0,n,days)
print(answer)