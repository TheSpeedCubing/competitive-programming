import datetime

s = input().split()
dt1 = datetime.date(int(s[0]), int(s[1]), int(s[2]))
s = input().split()
dt2 = datetime.date(int(s[0]), int(s[1]), int(s[2]))

print(abs((dt1 - dt2).days))