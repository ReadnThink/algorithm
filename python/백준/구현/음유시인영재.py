import sys
input = sys.stdin.readline

str = input().strip()
words = str.split()
space = int(input())
alpha = list(map(int, input().split()))

def write_content(idx):
    global is_worn
                
    alpha[idx] -= 1
    if alpha[idx] < 0:
        is_worn = True

def get_alpha_idx(w):
    if ord(w) >= 97:
        idx = ord(w) - ord('a')
    else:
        idx = ord(w) - ord('A')
    return idx

def write_title(ch):
    ret.append(ch)
    alpha_idx = get_alpha_idx(ch)
    write_content(alpha_idx)

space_limit = len(words)-1
if space < space_limit:
    print(-1)
else:
    ret = []
    is_worn = False
    for i,word in enumerate(words):
        for idx,w in enumerate(word):
            prev = ''
            if idx > 0:
                prev = word[idx-1]
            if w == prev:
                    continue
            alpha_idx = get_alpha_idx(w)
            write_content(alpha_idx)
        write_title(word[0])
        if is_worn:
            break
    if is_worn:
        print(-1)
    else:
        print(''.join(ret).upper())
