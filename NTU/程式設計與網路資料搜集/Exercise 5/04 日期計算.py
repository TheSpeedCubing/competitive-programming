import datetime

s = input().split()
dt = (datetime.date(int(s[0]), int(s[1]), int(s[2])) + datetime.timedelta(days=int(input())))

print(dt.strftime('%Y-%m-%d'))