import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
while T:
    commands = input().strip()
    n = int(input())
    arr = input().strip()
    arr = arr[1:-1]
    arr = arr.split(',')
    is_error = False
    
    arr = deque(arr)
    # deque가 비어있는데 자꾸 len이 1로나옴....
    # print('arr =',arr, len(arr))
    ret = 'error'
    #배열이 비어있는데 D를 사용한 경우에는 에러
    pointer = 0 # 0 앞에서부터 1 뒤에서부터
    for command in commands:
        if command == 'R':
            pointer = pointer^1
        else:
            if len(arr) == 0:
                is_error = True
                break            
            if len(arr) == 1:
                if arr[0] == '':
                    is_error = True
                    break            
            if pointer == 0:        
                arr.popleft()
            else:
                arr.pop()
    
    if is_error:
        print(ret)
    else:
        if pointer == 1:
            arr.reverse()
        print('['+','.join(arr)+']')
    T -= 1
    

