import sys
input = sys.stdin.readline
#startwith으로 C가 포함인지 확인하기
opcode = {"ADD": 0, "ADDC": 1, "SUB": 2, "SUBC": 3, "MOV": 4, "MOVC": 5,
      "AND": 6, "ANDC": 7, "OR": 8, "ORC": 9, "NOT": 10, "MULT": 12,
      "MULTC": 13, "LSFTL": 14, "LSFTLC": 15, "LSFTR": 16, "LSFTRC": 17,
      "ASFTR": 18, "ASFTRC": 19, "RL": 20, "RLC": 21, "RR": 22, "RRC": 23}

n = int(input())
commands = list(input().split() for _ in range(n))

for op, rD, rA, rB in commands:
    temp = ''
    # 0~4
    temp += format(opcode[op],'b').zfill(5)
    # 5
    temp += '0'
    # 6~8
    temp += format(int(rD),'b').zfill(3)
    # 9~11
    if rA == '0':
        temp += '000'
    else:
        temp += format(int(rA),'b').zfill(3)
    # 12~15
    if temp[4] == '0':
        temp += format(int(rB),'b').zfill(3)+'0'
    else:
        temp += format(int(rB),'b').zfill(4)
    # 출력 
    print(temp)