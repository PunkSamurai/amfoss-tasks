def gcd(a,b):
    for i in range(min([a,b]),0,-1):
        if a%i == 0 and b%i == 0:
            return i
    return 1

t = int(input())
outputs = []
for i in range(t):
    n = int(input())
    m = 1
    for i in range(1,n+1):
        m = (m*i)//gcd(m,i)
    outputs.append(m)

for i in outputs:
    print(i)

