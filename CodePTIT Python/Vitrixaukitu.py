s = "abcdabacbcad"
c = "a"
cnt = s.count(c)
if cnt == 1:
    print(s.find(c))
elif cnt > 1:
    print(str(s.find(c))+ " " + str(s.rfind(c)))
else:
    print("-1")