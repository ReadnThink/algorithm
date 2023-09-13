import sys

H,W = map(int, input().split())
arr = [list(map(str, input())) for _ in range(H)]
result = [ [-1]*W for _ in range(H)]

for i in range(H):
    time = 0
    for j in range(W):
        if arr[i][j] == 'c':
            time = 0
            result[i][j] = time
            time += 1
        elif arr[i][j] == '.' and time != 0:
            result[i][j] = time
            time += 1
        
            
            
for i in range(H):
    print(*result[i])