n = int(input())
string = input()
letters = ''
lettersInfo = {}

for i in string:
    if i not in letters:
        letters += i
        lettersInfo[i] = 1
    else:
        lettersInfo[i] += 1

c = ''
for i in letters:
    if lettersInfo[i]%2 != 0:
        if c == '':
            c = i
            lettersInfo[i] -= 1
        else:
            lettersInfo[i] -= 1

string = ''
n = 0
for i in letters:
    string = string[:n//2] + i*lettersInfo[i] + string[n//2:]
    n = len(string)

if c != '':
    string = string[:n//2] + c + string[n//2:]
    n = len(string)

print(n)
print(string)
