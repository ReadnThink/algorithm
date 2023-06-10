import sys
input = sys.stdin.readline

n,m,r = map(int,input().split())
choice = min(n,m)
arr = [list(map(int,input().split())) for _ in range(n)]
y1,x1,y2,x2 = 0,0,n-1,m-1

def printArr():
    for i in range(n):
        for j in range(m):
            print(arr[i][j], end=' ')
        print()
def rotate(y1,x1,y2,x2):
    right_top = arr[y1][x2] # arr[y1][x2-1]에 가아햠
    
    # 오른쪽
    for y in range(y1,y2):
        arr[y][x2] = arr[y+1][x2]
    # 아래
    for x in range(x2,x1,-1):
        arr[y2][x] = arr[y2][x-1]
    # 왼쪽
    for y in range(y2,y1,-1):
        arr[y][x1] = arr[y-1][x1]
    # 위
    for x in range(x1,x2):
        arr[y1][x] = arr[y1][x+1]
    
    arr[y1][x2-1] = right_top
    


for i in range(r):
    for j in range(choice//2):
        rotate(y1+j,x1+j,y2-j,x2-j)
printArr()
