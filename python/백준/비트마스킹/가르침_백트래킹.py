import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
from collections import deque

def check():
    cnt = 0
    for word in words:
        flag = True
        for s in word:
            if not alpha[ord(s) - ord('a')]:
                flag = False
                break
        if flag:
            cnt += 1
    return cnt

def dfs(depth, teach):
    global ret
    if teach == 0:
        ret = max(ret, check())
        return

    for i in range(26):
        if not alpha[i]:
            alpha[i] = True
            dfs(depth+1, teach-1)
            alpha[i] = False
        
N,K = map(int, input().split())
# K 가르침, N 단어 개수
words = [list(map(str, input().strip())) for _ in range(N)]

# a n t i c 필수
alpha = [False]*26
for i in 'a', 'n', 't','i','c':
    alpha[ord(i) - ord('a')] = True

ret = 0
if K < 5:
    print(0)
    exit()
elif K == 26:
    print(N)
    exit()
    
K = K - 5

dfs(0,K)
print(ret)