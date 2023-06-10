import sys
input = sys.stdin.readline

print("42를 2,8,16진수로 표현하기")
print(0b101010) # 2진수 b = binary(바이너리)
print(0o52) # 8진수 o = octal(옥탈)
print(0x2A) # 16진수 x = hexa decimal(헥사 데시멀)
print()

print("숫자에서 다른 진수의 문자열로 변환하기")
print(bin(42))
print(oct(42))
print(hex(42))
print(str(0b101010))
print(str(0o52))
print(str(0x2A))
print()

print("다른 진수의 문자열을 숫자형으로 변환하기")
print(int('0b101010',2))
print(int('0o52',8))
print(int('0x2A',16))
print()

print("format()을 통한 진법 변환")
print(format(42,'b'))
print(format(42,'o'))
print(format(42,'x'))
print(format(42,'X'))
print(format(42,'#b'))
print(format(42,'#o'))
print(format(42,'#x'))
print(format(42,'#X'))
print()

print("16진수를 2진수로")
print(format(0x2A,'b'))

print()
print("종합")
print("int : {0:d}, bin : {0:b}, oct : {0:o}, hex : {0:x}".format(42))