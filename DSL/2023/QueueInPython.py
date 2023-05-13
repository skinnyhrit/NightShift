class Node:
    value = None
    next = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def display(self):
        if(self.head == None and self.tail == None):
            print("\nQueue is empty\n")
        else:
            current = self.head
            while(current != None):
                print(str(current.value),end="\t")
                current = current.next

    def enqueue(self,value):
        temp = Node()
        temp.value = value
        temp.next = None
        if(self.tail == None):
            self.tail = temp
            self.head = self.tail     
        else:
            self.tail.next = temp
            self.tail = temp

    def dequeue(self):
        if(self.head == None):
            print("\nQueue is empty\n")
            return 0
        else:
            value = self.head.value
            temp = self.head
            self.head = self.head.next
            del temp
            if(self.head == None):
                self.tail = None
            return value


if __name__ == "__main__":
    ch = None
    value = None
    queue = Queue()
    while(True):
        print("\nWelcome to Queue in Python\n")
        print("1.Display Queue\n")
        print("2.Perform Enqueue Operation\n")
        print("3.Perform Dequeue Operation\n")
        print("4.Exit\n")
        print("Enter choice: ")
        ch = int(input())
        
        if(ch == 1):
            queue.display()
        elif(ch ==2):
            print("\nEnter value to enqueue\n")
            value = int(input())
            queue.enqueue(value)
        elif(ch == 3):
            value = queue.dequeue()
            print("\nDequeued value is ",value)
        elif(ch == 4):
            exit()
        else:
            print("\nwrong choice enter again\n")
            
