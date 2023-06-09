import sys
import copy
sys.setrecursionlimit(10000000)
input = sys.stdin.readline

n,m,k = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
r_info = [list(map(int,input().split())) for _ in range(k)]
visited = [False] * (k+1)
global min_value
min_value = sys.maxsize
# test 
def printArr(temp):
    for i in range(n):
        print(temp[i])
    print()

def get_min(temp):
    global min_value
    for i in range(n):
        min_value = min(min_value,sum(temp[i]))
    return min_value

def rotate(r,c,s,temp):
    # 배열 돌리기
    y1,x1,y2,x2 = (r-s)-1,(c-s)-1,(r+s)-1,(c+s)-1
    while x2-x1 >= 2:
        left_top = temp[y1][x1]
        # 왼
        for y in range(y1,y2):
            temp[y][x1] = temp[y+1][x1]
        # 아래
        for x in range(x1,x2):
            temp[y2][x] = temp[y2][x+1]
        # 오른
        for y in range(y2,y1,-1):
            temp[y][x2] = temp[y-1][x2]
        # 위
        for x in range(x2,x1,-1):
            temp[y1][x] = temp[y1][x-1]
        temp[y1][x1+1] = left_top
        y1 += 1
        x1 += 1
        y2 -= 1
        x2 -= 1
    return temp
per = []
def dfs(depth):
    if depth == len(r_info):
        # print(per)
        # 배열을 변경하는데 새로운 배열이 필요
        temp = copy.deepcopy(arr) 
        for info in per:
            temp = rotate(info[0],info[1],info[2], temp)
        # 최소값 구하기
        get_min(temp)
        # printArr(temp)
        return
    # 순열구하기
    for i in range(len(r_info)):
        if visited[i]:
            continue
        visited[i] = True
        per.append(r_info[i])
        dfs(depth+1)
        per.pop()
        visited[i] = False
        

# for info in r_info:
#     rotate(info[0],info[1],info[2])
dfs(0)
print(min_value)