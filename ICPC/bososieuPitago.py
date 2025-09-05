import math
a = int(input())
a_0 = a ** 2
a_0 *= 2
ok = 0
for b in range(1, 100005):
    b_2 = b ** 2
    if(a_0 > b_2):
        c_2 = a_0 - b_2
        c = int(math.sqrt(c_2))
        if( c < 100001 and c * c == c_2):
            if c != b and c != a and b != a:
                ok = 1
                print("YES")
        #print(f"a: {a}, b: {b}, c: {c}")
                break
if(ok == 0):
    print("NO")
