def fix(s):
    return max(0, min(int(s), 100))


task = sorted([int(x) for x in input().split()])

SC = 0.0
taskTotal = 0.0
for i in range(1, 6):
    taskTotal += max(0, task[i])

SC += min(100.0, taskTotal / 5) * 0.5

exam = sorted([int(x) for x in input().split()])

SC += min(100, exam[1]) * 0.15 + min(100, exam[0]) * 0.1 + int(input()) * 0.25
SC = round(SC)

rank = ["X", "F", "C-", "C", "C+", "B-", "B", "B+", "A-", "A", "A+"]
size = [0, 59, 62, 66, 69, 72, 76, 79, 84, 89, 100]

result = 0
for i in range(11):
    if SC <= size[i]:
        break
    result += 1
print(str(SC) + " " + rank[fix(result + (-2 if task[0] == -1 else 0))])