
t = int(input())
for i in range (t):
    n = input()
    num = 0
    tong = None
    for i, ch in enumerate(n):
        if ch.isdigit():
            tong = (0 if tong is None else tong) * 10 + int(ch)
        if ch.isalpha():
            if tong is not None:
                num = max(num, tong)
                tong = None
    
    if tong is not None:
        num = max(num, tong)

    print (num)
