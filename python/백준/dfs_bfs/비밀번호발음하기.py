import sys

while True:
    word = input().strip()
    if word == 'end':
        break
    
    is_acceptable = False
    
    moum = ['a','e','i','o','u']
    for ch in moum:
        if ch in word:
            is_acceptable = True
            break
    
    A = 0
    B = 0
    prev = word[0]
    for i, ch in enumerate(word):
        if ch in moum:
            A += 1
            B = 0
        else:
            B += 1
            A = 0
        
        if A >= 3 or B >= 3:
            is_acceptable = False
            break
        if i > 0:
            if word[i] != 'e' and word[i] != 'o' and word[i] == prev:
                is_acceptable = False
        prev = word[i]
    
    if is_acceptable:
        print('<' + word + '> is acceptable.')
    else:
        print('<' + word + '> is not acceptable.')