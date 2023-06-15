import sys
input = sys.stdin.readline


def input_values(arr, op):
    while True:
        temp = input().strip()
        if temp == op:
            break
        arr.append(temp)    
    return arr
words = input_values([], '-')
puzzles = input_values([], '#')

print(words)
print(puzzles)

# 조합으로 일일히 다 구해본다.
# def combi(start, depth, limit, word, puzzle, visited):
    # if depth == limit:
    #     if word in words:

# for p in puzzles:
    # for i in range(4,10):
    #     combi(0,0,i,'',p, [False for _ in range(10)])