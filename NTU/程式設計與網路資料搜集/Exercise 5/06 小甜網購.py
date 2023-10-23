import datetime


ts1 = datetime.datetime.strptime(input(), "%Y-%m-%d %H:%M:%S.%f%z")
ts2 = datetime.datetime.strptime(input(), "%Y-%m-%d %H:%M:%S.%f%z")

print(ts1 - datetime.datetime.fromtimestamp(float(input()), tz=ts1.tzinfo) + ts2)