/*
	Jason Bonilla 2018
	Linked list of nodes where each node contains a data field and a 
	reference(link) to the next and previous node in the list.
*/
import java.io.*;

class List
{
	public class Node
	{
		
		int index;
		public Node next;
		public Node prev;
		
		
		public Node(){
		}
		public Node(int index)
		{
			this.index = index;
		}	
	}
		
		public Node cursor;
		public Node head; 
		public Node tail; 
		public int index;
		
		
		public List()
		{
			head = null;
			tail = null;
			index = -1;
			cursor = null;
		}

		
		public int length() 
		{
			if(empty() == true)
			{
				return 0;
			}
			else
			{
				Node hold = new Node();
				hold = head;
				int count = 0;
				while(hold != null)
				{
					count++;
					hold = hold.next;
				}
	            return count;
			}
		}

		public int index()	
		{
			if(cursor == null)
			{
				return -1;
			}
			return cursor.index;
		}

		
		public int front() 
		{
			if(empty() == true)
			{
				return -1;
			}
			return head.index;
		}

		
		public int back() 
		{
			if(empty() == true)
			{
				return -1;
			}
			return tail.index;
		}
		
		
		int get()
		{
			if(cursor != null){
				return cursor.index;
			}
			else
				return -1;
		}

		
		public boolean equals(List L)
		{
			Node node = new Node(); 
			Node node1 = new Node(); 
			node = this.head;
			node1 = L.head;
			while(node != null && node1 != null){
				if(node.index == node1.index){
					node = node.next;
					node1 = node1.next;
				}
				else{
					return false;
				}
			}
			return true;
		}

		
		public  void clear()
		{
			this.head = null;
			this.tail = null;
		}

		
		public  void moveFront()
		{
			if(empty() == true)
			{
				return;		
			}
			cursor = this.head;
			cursor.prev = this.head.prev;
			cursor.next = this.head.next;
			
		}

		
		public  void moveBack()
		{
			if(empty() == true)
			{
				return;	
			}
			cursor = this.tail;
			cursor.prev = this.tail.prev;
			cursor.next = this.tail.next;	
		}

		public void movePrev()
		{
			if(cursor == null){
				return;
			}
			else if(cursor == head){
				cursor = null;
			}
			else{
				cursor = cursor.prev;
			}
		}

		
		public  void moveNext() 
		{
			if(cursor == null){
				return;
			}
			else if(cursor == tail){
				cursor = null;
			}
			else{
				cursor = cursor.next;
			}
		}

		
		public void prepend(int numb) 
		{
			Node late = new Node( numb); 

			if(head == null){
				head = late;	
				tail = late;	
			}
			else{
				head.prev = late;	
				late.next = head; 
				head = late; 		
			}
		}

		
		public void append(int numb) 
		{
			Node last = new Node(numb);
			if(head == null){
				head = last;
				tail = last;
			}
			else{
				last.prev = tail;
				tail.next = last;
				tail = last;}
		}


		
		public void insertBefore(int numero) 
		{
			if(empty() == true){
				System.err.println("********************");
				System.exit(1);
			}
			else if(cursor == null){
				System.err.println("********************");
				System.exit(1);
			}
			else
			{
				if(cursor == head){
					prepend(numero);
				}
				else{
					Node recent = new Node(numero);
					cursor.prev.next = recent;
					recent.prev = cursor.prev;
					cursor.prev = recent;
					recent.next = cursor;
				}
			}
		}

		
		public  void insertAfter(int numero) 
		{
			if(empty() == true){
				System.err.println("********************");
				System.exit(1);
			}
			else if(cursor == null){
				System.err.println("********************");
				System.exit(1);
			}
			else{
				if(cursor == tail){
					append(numero);
				}
				else{
					Node recent = new Node(numero);
					cursor.next.prev = recent;
					recent.next = cursor.next;
					cursor.next = recent;
					recent.prev = cursor;
				}
			}
		}

		
		public void deleteFront()
		{
			head = head.next;
			head.prev = null;
		}

		
		public void deleteBack()
		{
			tail = tail.prev;
			tail.next = null;
		}

		
		public void delete()
		{
			if(cursor == head){
				deleteFront();
				
			}
			else if(cursor == tail){
				deleteBack();
				
			}
			else{
				cursor.next.prev = cursor.prev;
				cursor.prev.next = cursor.next;
				cursor.prev = null;
				cursor.next = null;
			}
		}

		
		public String toString()
		{
			Node craps = new Node();
			String list = "";
			craps = this.head;
			while(craps != null)
			{
				list = list+craps.index + " ";
				craps = craps.next;
			}
			return list;
		}

		
		public List copy()
		{
			List newList = new List();
			Node temp = new Node();
			temp = this.head;

			while(temp != null){
				newList.append(temp.index);
				temp = temp.next;
			}

			return newList;
		}

		
		public boolean empty() 
		{
			if(tail == null && head == null)
			{
				return true;
			}
			return false;
		}
		
}
