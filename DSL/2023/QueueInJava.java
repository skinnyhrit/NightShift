import java.util.*;
import java.lang.*;

class Node
{
	int value;
	Node next;
}


class Queue
{
	Node head;
	Node tail;
	void Queue()
	{
		head = null;
		tail = null;		
	}
	
	void display()
	{
		if(head == null)
		{
			System.out.println("\nQueue is empty\n");
		}
		else
		{
			Node current = head;
			while(current != null)
			{
				System.out.print(current.value+" ");
				current = current.next;
			}		
		}	
	}

	void enqueue(int value)
	{
		Node temp = new Node();
		temp.value = value;
		temp.next = null;	
		if(tail == null)
		{
			tail = temp;
			head = tail;	
		}
		else
		{
			tail.next = temp;
			tail = temp;
		}		
	}

	int dequeue()
	{
		if(head == null)
		{
			System.out.println("\nQueue is empty\n");
			return 0;	
		}
		else
		{
			int value = head.value;
			Node temp = head;
			temp = null;
			head = head.next;
			if(head == null)
			{
				tail = null;
			}
			return value;
		}	
	}
}

public class QueueInJava
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int ch;
		int value;
		Queue queue = new Queue();
		while(true)
		{
			System.out.println("\nWelcome to my Queue in java\n");
			System.out.println("1.Display Queue\n");
			System.out.println("2.Perform Enqueue Operation\n");
			System.out.println("3.Perform Dequeue Operation\n");
			System.out.println("4.Exit\n");
			System.out.println("Choice: ");
			ch = sc.nextInt();
			switch(ch)
			{
				case 1:	queue.display();		
					break;
				case 2: System.out.println("\nEnter value to enqueue\n");
				       	value = sc.nextInt();	
					queue.enqueue(value);
					break;
				case 3: value = queue.dequeue();
					System.out.println("\nDequeued value: "+value);
					break;
				case 4: System.exit(0);
					break;
				
				default: System.out.println("\nWrong choice\n");
				 	 
			}
		}
	}
}
