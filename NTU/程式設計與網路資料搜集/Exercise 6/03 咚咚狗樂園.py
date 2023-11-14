# 完成以下程式即可
dogs = []
feed = []
walk = []


class Dogs:
    def __init__(self, n):
        for i in n:
            dogs.append(i)

    def get_in(self, n):
        dogs.append(n)

    def get_out(self, n):
        dogs.remove(n)

    def feed(self, n):
        ##if n not in feed:
        feed.append(n)
        s = ""
        for i in feed:
            if s == "":
                s = i
            else:
                s = s + " " + i
        return s

    def play(self, n):
        walk.append(n)
        s = ""
        for i in walk:
            if s == "":
                s = i
            else:
                s = s + " " + i
        return s

    def __len__(self):
        return len(dogs)

    def peek(self):
        return str(dogs)

    def __str__(self):
        s = ""
        for i in dogs:
            if s == "":
                s = i
            else:
                s = s + "-" + i
        return s

      
# 程式會這樣跑
# command = []
# while True:
#     try:
#         command.append(input().split())
#     except EOFError:
#         break
# dog = Dogs(command[0])
# for c in command[1:]:
#     if c[0] == 'Print':
#         print(dog)
#     if c[0] == 'GetIn':
#         dog.get_in(c[1])
#     if c[0] == 'GetOut':
#         dog.get_out(c[1])
#     if c[0] == 'Len':
#         print(len(dog))
#     if c[0] == 'Peek':
#         print(dog.peek())
#     if c[0] == 'Feed':
#         print(dog.feed(c[1]))
#     if c[0] == 'Walk':
#         print(dog.play(c[1]))