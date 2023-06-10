import sys
input = sys.stdin.readline

# 공백기준 자르기
arr = input().split()
base = arr[0]
del arr[0]
for str in arr:
    str = str.replace(',', '').replace(';','')
    
    print(base, end='')
    # 거꾸로 탐색
    for i in range(len(str)-1, -1, -1):
        if not str[i].isalpha():
            if str[i] == ']':
                print('[',end='')
            elif str[i] == '[':
                print(']',end='')    
            else:
                print(str[i], end='')
        else:
            print(end=' ')
            print(str[0:i+1]+';')
            break
        