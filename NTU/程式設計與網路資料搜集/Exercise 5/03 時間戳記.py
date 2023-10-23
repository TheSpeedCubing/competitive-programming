import datetime

print(
    datetime.datetime.utcfromtimestamp(int(input()))
    .strftime('%Y-%m-%d %H:%M:%S')
)