import sys
input = sys.stdin.readline

# DNA의 연속된 일부분을 다른 DNA로 교체한다
# 바이러스에 의해 교체된 DNA의 길이를 구해보려고 한다.
# 두 번째 DNA로 바뀌기 위해 첫 번째 DNA에 삽입되어야 하는 연속된 DNA 조각의 길이를 구하식오
# 연속된 DNA 조각은 삽입되기 전, 원래 그 자리에 있는 DNA를 제거할 수도 있다.

# DNA는 {A, G, C, T}로만 이루어져 있으며, 길이는 1보다 크거나 같고, 100000 작거나 같다.

DNA = ['A', 'G', 'C', 'T']
original = input().strip()
new = input().strip()

original_len = len(original)
new_len = len(new)

l,r = -1,-1

for i, ch in enumerate(original):
    if ch != new[i] and ch in DNA:
        l = i
        break

idx = original_len-1
r_cnt = 0
for i in range(len(new)-1, l-1, -1):
    if original[idx] != new[i] and original[idx] in DNA:
        break
    r_cnt += 1
    idx -= 1

# print(l,r_cnt)
print(len(new) - (l + r_cnt))
    


    
    