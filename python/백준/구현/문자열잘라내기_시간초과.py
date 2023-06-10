import sys
import copy
sys.setrecursionlimit(10000000)
input = sys.stdin.readline

n,m = map(int,input().split())
words = [list(input().strip()) for _ in range(n)]
words_set = set()
count = -1
isFindStr = False
for i in range(n):
    
    for j in range(m):
        if isFindStr:
            break
        temp = ''
        for k in range(i,n):
            # print(k,j, end=' ')
            # print(words[k][j], end='')    
            temp += words[k][j]
        if temp in words_set:
            # print()
            # print('find',temp)
            isFindStr = True
            break
        else:
            print(temp)
            words_set.add(temp)
        # print()
    if isFindStr:
        break
    count += 1
# print(words_set)
print(count)