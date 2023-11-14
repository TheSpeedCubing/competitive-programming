class Student:
    def __init__(self, , ):
        # TODO: set attributes
        
    def __str__(self):
        return f'{self.name} {self.next or ""}' 
      
def remove_naughty(head, target):
    s = ""
    while True:
        if head is None:
            break
        if head.name != target:
            s = s + head.name +" "
        head = head.next
        
    return s
    
# the class and function will be used as follows:
# lst = input().split()
# target = input()

# tail = Student(lst[-1], None)
# for i in range(len(lst) - 2, -1, -1):
#     head = Student(lst[i], tail)
#     tail = head
# if len(lst) == 1:
#     head = tail

# print(remove_naughty(head, target))
