import math

s = input().split()
i = int(s[0])
xt = int(s[1])
T = int(s[2])
L = int(s[3])
total = 0
for t in range(T):
    xt -= (1 + 0.5*(t+1))
    xt = L if xt < L else xt
    total += math.ceil(i * xt / 100.0)
print(total)
 