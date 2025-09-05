import math

t = int(input())
for i in range(t):
    s = input()
    num = 1e18
    tong = None
    for index, ch in enumerate(s):
        if ch.isdigit():
            tong = (0 if tong is None else tong) * 10 + int(ch)
        elif ch.isalpha():
            if tong is not None:
                num = min(num, tong)
                tong = None
    if tong is not None:
        num = min(tong, num)
    print(num)