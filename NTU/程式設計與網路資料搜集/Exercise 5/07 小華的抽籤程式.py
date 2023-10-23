import random

s = input().split()

r0 = int(s[0])
ri = r0
cnt = int(s[1])
for i in range(cnt):
    random.seed(r0)
    ri = (random.randint(1, 1000000000) * ri + random.randint(1, 1000000000)) % random.randint(1, 10000)
    print(ri)