def gcd(i1, i2):
    while i2:
        temp = i1
        i1 = i2
        i2 = temp % i2
    return i1


intArr = [int(n) for n in input().split()]
intArr2 = [int(n) for n in input().split()]
result = [0] * len(intArr2)
for i in range(len(intArr2)):
    result[i] = gcd(intArr[i], intArr2[i])
print(result)