#TODO: finish this class
arrayList = []

class LittleTrain():
    def __init__(self,n):
        for i in n:
            arrayList.append(i)
        pass

    def __str__(self):
        s = ""
        for i in arrayList:
            if s == "":
                s = i
            else:
                s = s + "-" + i
        return s

    def peek(self):
        return arrayList[len(arrayList)-1]

    def get_in(self,n):
        arrayList.append(n)
        pass

    def get_out(self):
        return arrayList.pop()

    def __len__(self):
        return len(arrayList)

    def is_empty(self):
        return len(arrayList) == 0

# the class will be used as follows:
# command = []
# while True:
#     try:
#         command.append(input().split())
#     except EOFError:
#         break
# train = LittleTrain(command[0])
# for c in command[1:]:
#     if c[0] == 'Print':
#         print(train)
#     if c[0] == 'GetIn':
#         train.get_in(c[1])
#     if c[0] == 'GetOut':
#         print(train.get_out())
#     if c[0] == 'Len':
#         print(len(train))
#     if c[0] == 'IsEmpty':
#         print(train.is_empty())
#     if c[0] == 'Peek':
#         print(train.peek())