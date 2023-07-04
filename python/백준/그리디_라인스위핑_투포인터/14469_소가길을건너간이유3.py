import sys
input = sys.stdin.readline

N = int(input())
cow = list(list(map(int, input().split()) )for _ in range(N))
cow.sort(key=lambda x : (x[0], x[1]))

time = 0

for arrive, scan_time in cow:
    if arrive > time:
        time = arrive
    time += scan_time

print(time)