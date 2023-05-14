import java.util.*;
import java.lang.*;

class Node
{
	int value;
	Node prev;
}

class Stack
{
	Node top;

	void Stack()
	{
		top = null;
	}

	void display()
	{	
		if(top == null)
		{
			System.out.println("\nStack is empty!!\n");
		}
		else
		{
			Node current = top;
			while(current != null)
			{
				System.out.print(current.value+"\t");
				current = current.prev;
			}
		}
	}

	void push(int value)
	{
		Node temp = new Node();
		temp.value = value;
		temp.prev = null;
		if(top == null)
		{
			top = temp;	
		}
		else
		{
			temp.prev = top;
			top = temp;
		}
	}

	int pop()
	{
		int value = 0;
		if(top == null)
		{
			System.out.println("\nStack is empty!!\n");
			return value;
		}
		else
		{
			value = top.value;
			Node temp = top;
			top = top.prev;
			temp = null;
			return value;
		}
		
	}
}

class StackInJava
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int value;
		int ch;
		Stack stack = new Stack();
		while(true)
		{
			System.out.println("\nWelcome to Stack in Java\n");
			System.out.println("1.Display\n");
			System.out.println("2.Push\n");
			System.out.println("3.Pop\n");
			System.out.println("4.Exit\n");
			ch = sc.nextInt();
			switch(ch)
			{
				case 1: stack.display();
					break;
				case 2: System.out.println("\nEnter value to Push\n");
					value = sc.nextInt();
					stack.push(value);
					break;
				case 3: value = stack.pop();
					System.out.println("\nPopped value is: "+value+"\n");
					break;
				case 4:	System.exit(0); 
				
				default: System.out.println("\nWrong choice enter again\n");
			}	
				
		}
	}
}
