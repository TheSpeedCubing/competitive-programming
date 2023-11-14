class Student:
    def __init__(self, name , next):
        self.name = name
        self.next = next
        # TODO: set attributes
      
def reverse_students(head):
    s = ""
    while True:
        if head is None:
            break
        s = head.name+" "+ s
        head = head.next
    return s
    # TODO: finish function return Student object
    
# the class and function will be used as follows:
# lst = input().split()

# tail = Student(lst[-1], None)
# for i in range(len(lst) - 2, -1, -1):
#     head = Student(lst[i], tail)
#     tail = head
# if len(lst) == 1:
#     head = tail

# print(reverse_students(head))
