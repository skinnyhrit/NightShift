class Node:
    value = None;
    prev = None;

class Stack:
    def __init__(self):
        self.top = None

    def display(self):
        if(self.top == None):
            print("\nStack is Empty!!\n")
        else:
            current = self.top
            while(current != None):
                print(current.value, end="\t")
                current = current.prev

    def push(self, value):
        temp = Node()
        temp.value = value
        temp.prev = None
        if(self.top == None):
            self.top = temp
        else:
            temp.prev = self.top
            self.top = temp 
    
    def pop(self):
        value = 0
        if(self.top == None):
            print("\nStack is empty\n") 
        else:
            value = self.top.value
            temp = self.top
            self.top = self.top.prev
            temp = None
            
        return value

if __name__ == "__main__":
    ch = None
    value = None
    stack = Stack()
    while(True):
        print("\nWelcme to Stack in Python\n")
        print("1.Display\n")
        print("2.Push\n")
        print("3.Pop\n")
        print("4.Exit\n")
        print("Enter choice: ")
        ch = int(input())

        if(ch == 1):
            stack.display()
        elif(ch == 2):
            print("\nEnter value to push\n")
            value = int(input())
            stack.push(value)
        elif(ch == 3):
            value = stack.pop()
            print("\nPopped value is: "+str(value))
        elif(ch == 4):
            exit()
        else:
            print("\nWrong choice enter again\n")
