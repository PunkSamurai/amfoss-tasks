pList = []
for i in range(100, 1000):
    for j in range(100, 1000):
        n = i*j
        s = str(n)
        if len(s) == 6:
            if s == s[::-1] and n not in pList:
                pList.append(n)
pList.sort()
print(pList)
print(len(pList))