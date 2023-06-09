import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)

n = int(input())
arr = input().strip()
m = (n // 5)
# for i in range(5):
#     for j in range(m):
#         print(arr[j+(i*m)], end='')
#     print()


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

def printArr(temp):
    print('출력!---')
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
    # print('cnt=',cnt)
    if cnt == 5:
        return 1
    # if temp == num[11]:
    #     return 11
    
    
    

def check_number(idx):
    # print('start idx = ', idx,' m =',m)
    temp = []
    # 마지막이 1일경우
    # if idx == m-1:
    #     # print('마지막인경우')
    #     for i in range(5):
    #         temp.append(arr[idx + (i * m)])
    #         temp.append('.')
    #         temp.append('.')
    # else:    
        # 마지막에 1이 아닐경우
    for i in range(5):
        for j in range(idx,idx+3):
            # 마지막이 1인경우
            if j + (i*m) >= ((i+1)*m):
                temp.append('.')
            else: # 마지막이 1이 아닌경우
                temp.append(arr[j + (i*m)])
                # print(j + (i*m),end='')
            # print()
    # printArr(temp)
    return numberMatch(temp)
    
ret = []
i = 0
while True:
    if i >= m:
        break
    if arr[i] == '#':
        # print('i in # = ',i)
        number = check_number(i)
        ret.append(str(number))
        # print(number)
        if number == 1:
            i+=1
        else:
            i+=2
    i += 1
print(''.join(ret))
