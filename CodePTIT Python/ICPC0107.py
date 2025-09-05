def minSum(x, y, p, q): # p < q
    a =""
    for _, ch in enumerate(x):
        if ch == str(q):
            a += str(p)
        else:
            a += ch
    b = ""
    for _, ch in enumerate(y):
        if ch == str(q):
            b += str(p)
        else:
            b += ch
    return int(a) + int(b)

def maxSum(x, y, p, q): # p < q
    a =""
    for _, ch in enumerate(x):
        if ch == str(p):
            a += str(q)
        else:
            a += ch
    b = ""
    for _, ch in enumerate(y):
        if ch == str(p):
            b += str(q)
        else:
            b += ch
    return int(a) + int(b)
         


t = int(input())
for i in range(t):
    p, q = map(int, input().split())
    x = input()
    if (len(x.split())) > 1:
        x, y = x.split()
    else:
        y = input()

    if p > q:
        p,q = q,p
    tong = minSum(x,y,p,q)
    print(tong, end=" ")
    tong2 = maxSum(x,y,p,q)
    print(tong2)
    
