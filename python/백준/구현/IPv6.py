import sys
from collections import deque
# input = sys.stdin.readline

# 각 그룹의 앞자리의 0의 전체 또는 일부를 생략
# 만약 0으로만 이루어져 있는 그룹이 있을 경우 
    # 그 중 한 개 이상 연속된 그룹을 하나 골라 콜론 2개(::)로 바꿀 수 있다.

IP = input().split(':') # 개행문자가 들어와서 input = sys.stdin.readline 주석처리
ret = []
zero_idx = []
for i,ip in enumerate(IP):
    if ip != '':
        ret.append(ip.zfill(4))
    else:
        ret.append('zero')
        zero_idx.append(i)
# print(zero_idx)
# print(ret)
if zero_idx:
    for i,zero in enumerate(zero_idx):
        if i == 0:
            ret[zero] = '0000'
        else:
            del ret[zero]
    idx = zero_idx[0]
    while len(ret) < 8:
        # print(f"{idx=}")
        ret.insert(idx, '0000')
        idx += 1
print(':'.join(ret))

# def solution(arr):
#     IP = arr.split(':')
#     ret = []
#     zero_idx = []
#     for i,ip in enumerate(IP):
#         if ip != '':
#             ret.append(ip.zfill(4))
#         else:
#             ret.append('zero')
#             zero_idx.append(i)

#     if zero_idx:
#         for zero in zero_idx:
#             ret[zero] = '0000'

#         idx = zero_idx[0]
#         while len(ret) != 8:
#             # print(f"{idx=}")
#             ret.insert(idx, '0000')
#             # idx += 1
#     print(':'.join(ret))
#     return ':'.join(ret)

# print(solution('2001:db8:85a3::8a2e:370:7334') == '2001:0db8:85a3:0000:0000:8a2e:0370:7334')
# print(solution('25:09:1985:aa:091:4846:374:bb') == '0025:0009:1985:00aa:0091:4846:0374:00bb')
# print(solution('::1') == '0000:0000:0000:0000:0000:0000:0000:0001')
# print(solution('0000:0000:0000::0000:0000:0000:0000')=='0000:0000:0000:0000:0000:0000:0000:0000')