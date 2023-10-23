ans = input().replace(" ", "")

questionCnt = len(ans)

rate = [0.0] * questionCnt
userCnt = int(input())

for i in range(userCnt):
    s = input().split(" ", 1)
    submit = s[1].replace(" ", "")

    score = 0
    for i in range(questionCnt):
        if submit[i] == ans[i]:
            score += 100.0 / questionCnt
            rate[i] += 100.0 / userCnt

    print(s[0] + " " + str(int(score)))
for i in rate:
     print(str(round(i , 2)) + "% ",end='')