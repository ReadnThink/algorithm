import sys
input = sys.stdin.readline

n = int(input())
words = [[input().split()] for _ in range(n)]
keyCheck = []

for word in words:
    for w in word:
        isPossible = False
        for i in range(len(w)):
            first = w[i][0].upper()
            if first not in keyCheck:
                keyCheck.append(first)
                w[i] = '[' + w[i][0] + ']' + w[i][1:]
                print(' '.join(w))
                isPossible = True
                break
                
        if not isPossible: # 첫글자가 이미 단축키라면
            find_not_pick = False
            for i in range(len(w)):
                if find_not_pick:
                    break
                for j in range(len(w[i])):
                    if w[i][j].upper() not in keyCheck: 
                        keyCheck.append(w[i][j].upper())
                        w[i] = w[i][:j] + '[' + w[i][j] + ']' + w[i][j+1:]
                        print(' '.join(w))
                        find_not_pick = True
                        break
            
            if not find_not_pick:
                print(' '.join(w))
            
# print(words)