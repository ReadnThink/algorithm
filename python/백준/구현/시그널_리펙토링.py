import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

n = int(input())
arr = input().strip()
m = (n // 5)

num = {
    0: [
        '#','#','#',
        '#','.','#',
        '#','.','#',
        '#','.','#',
        '#','#','#'
    ],

    1: [
        '#','.','.',
        '#','.','.',
        '#','.','.',
        '#','.','.',
        '#','.','.'
    ],

    2: [
        '#','#','#',
        '.','.','#',
        '#','#','#',
        '#','.','.',
        '#','#','#'
    ],

    3: [
        '#','#','#',
        '.','.','#',
        '#','#','#',
        '.','.','#',
        '#','#','#'
    ],
    4: [
        '#','.','#',
        '#','.','#',
        '#','#','#',
        '.','.','#',
        '.','.','#'
    ],
    5: [
        '#','#','#',
        '#','.','.',
        '#','#','#',
        '.','.','#',
        '#','#','#'
    ],
    6: [
        '#','#','#',
        '#','.','.',
        '#','#','#',
        '#','.','#',
        '#','#','#'
    ],
    7: [
        '#','#','#',
        '.','.','#',
        '.','.','#',
        '.','.','#',
        '.','.','#'
    ],
    8: [
        '#','#','#',
        '#','.','#',
        '#','#','#',
        '#','.','#',
        '#','#','#'
    ],
    9: [
        '#','#','#',
        '#','.','#',
        '#','#','#',
        '.','.','#',
        '#','#','#'
    ],
    11: [
        '#','.','#',
        '#','.','#',
        '#','.','#',
        '#','.','#',
        '#','.','#'
    ]
}
def printOriginal():
    for i in range(5):
        for j in range(m):
            print(arr[j+(i*m)], end='')
        print()

def printArr(temp):
    # print('출력!---')
    # print(temp)
    for i in range(5):
        for j in range(3):
            print(temp[j+(i*3)], end='')
        print()

def numberMatch(temp):
    for i in range(10):
        if temp == num[i]:
            return i
    # 가로로 1이면 1이다.
    cnt = 0
    for i in range(5):
        for j in range(1):
            if temp[j + (i*3)] == '#':
                cnt += 1
    if cnt == 5:
        return 1
    
    
    

def check_number(idx):
    temp = []
    for i in range(5):
        for j in range(idx,idx+3):
            # 마지막이 1인경우
            if j + (i*m) >= ((i+1)*m):
                temp.append('.')
            else: # 마지막이 1이 아닌경우
                temp.append(arr[j + (i*m)])
    # printArr(temp)
    return numberMatch(temp)
    
ret = []
i = 0
while True:
    if i >= m:
        break
    if arr[i] == '#':
        number = check_number(i)
        ret.append(str(number))
        if number == 1: # 숫자 1인경우 2간 전진
            i+=1
        else: # 숫자 1이 아니면 3칸전진
            i+=2
    i += 1
    
# printOriginal() # 원본 배열 출력해보기
print(''.join(ret))
