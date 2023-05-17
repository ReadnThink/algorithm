import math
n = int(input())
list = [2,3,5,7]

def isPrime(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def dfs(num):
    if len(str(num)) == n:
        print(num)
        return
    
    for i in range(1,10):
        next = (num * 10) + i
        if isPrime(next):
            dfs(next)

for i in range(len(list)):
    dfs(list[i])