result = [0] * 26
order = []

while True:
    s = input()
    if s == "0":
        for i in order:
            print(chr(i + 97) * result[i])
        break
    else:
        for c in s:
            i = ord(c) - 97
            if result[i] == 0:
                order.append(i)
            result[i] += 1