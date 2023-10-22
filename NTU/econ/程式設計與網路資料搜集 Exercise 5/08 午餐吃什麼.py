import random

n = int(input())
if n == 0:
    print("吃空氣")
else:
    random.seed(942)
    row = random.randint(1,n)
    for i in range(n):
        s = input().split()
        if row == i+1:
            print(s[0] + " " + s[random.randint(1, len(s) - 1)])
