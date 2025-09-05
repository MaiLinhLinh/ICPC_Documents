t = int(input())

for i in range (t):
    b = int(input())
    x = input()
    if(b == 2):
        print(x,end="")
    elif b == 4:
        s = ""
        num = 0
        for i, ch in enumerate(reversed(x)):
            n = int(ch)
            if n == 1:
                if i % 2 == 0:
                    num += 1
                else:
                    num += 2
            if i % 2 == 1:
                if(i == len(x)-1 and num == 0):
                    continue
                s += str(num)
                num = 0
        if num != 0:
            s += str(num)          
        for ch in reversed(s):
            print(ch, end="")
    elif b == 8:
        s = ""
        num = 0
        for i, ch in enumerate(reversed(x)):
            n = int(ch)
            if n == 1:
                if i % 3 == 0:
                    num += 1
                elif i % 3 == 1:
                    num += 2
                else:
                    num += 4
            if(i % 3 == 2):
                if(i == len(x)-1 and num == 0):
                    continue
                s += str(num)
                num = 0

        if num != 0:
            s += str(num)
        
        for ch in reversed(s):
            print(ch, end="")
    else:
        s = ""
        num = 0
        for i, ch in enumerate(reversed(x)):
            n = int(ch)
            if n == 1:
                if i % 4 == 0:
                    num += 1
                elif i % 4 == 1:
                    num += 2
                elif i % 4 == 2:
                    num += 4
                else:
                    num += 8
            if(i % 4 == 3):
                if(i == len(x)-1 and num == 0):
                    continue
                if(num == 10):
                    s += "A"
                elif num == 11:
                    s += "B"
                elif num == 12:
                    s += "C"
                elif num == 13:
                    s += "D"
                elif num == 14:
                    s += "E"
                elif num == 15:
                    s += "F"
                else:
                    s += str(num)
                num = 0
        if num != 0:
            s += str(num)
        
        for ch in reversed(s):
            print(ch, end="")
    print()
            


