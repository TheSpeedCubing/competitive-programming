s = set()

class User:
    def __init__(self, name, number):
        self.name = name
        self.number = number
        s.add(self)


class Phonebook:
    def search(self, n):
        for i in s:
            if i.name == n:
                return i.number
            elif i.number == n:
                return i.name
        return "Cannot find " + n

    def add(self, name, number):
        User(name, number)

    def delete(self, n):
        toRemove = set()
        for i in s:
            if i.name == n or i.number == n:
                toRemove.add(i)
        for i in toRemove:
            s.remove(i)

    def modify(self, n, n2):
        for i in s:
            if i.name == n:
                i.name = n2
                break
            elif i.number == n:
                i.number = n2
                break

# We will judge your code with the following scripts

# pbook = Phonebook()
# while True:
#     args = input().split()
#     if args[0] == "end":
#         break
#     if args[0] == "s":
#         print(pbook.search(args[1]))
#     elif args[0] == "a":
#         pbook.add(args[1], args[2])
#     elif args[0] == 'd':
#         pbook.delete(args[1])
#     elif args[0] == 'm':
#         pbook.modify(args[1], args[2])