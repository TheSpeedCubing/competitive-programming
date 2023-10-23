def calc(s):
    t = 0
    for char in s.lower():
        t += ord(char) - 96
    return t


def sort_dict(s):
    return sorted(s.split(), key=calc)