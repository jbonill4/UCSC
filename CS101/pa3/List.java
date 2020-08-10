/*
	Jason Bonilla 2018
*/

public class List 
{
	
	public class Node
	{
		
		private Object nodeEntry;
		
		private Node next;
		private Node prev;
		
		public Node()
		{}
		public Node(Object x)
		{
			this.nodeEntry = x;
			this.next = null;
			this.prev = null;
		}
		public void changeNodeEntry(Object x)
		{
			this.nodeEntry = x;
		}
		
	}

	private Node head;
	private Node tail; 
	private int index;
	private Node cursor;
	
	public  List()
	{
		this.head = null;
		this.tail = null;
		this.index = 0;
		this.cursor = null;	
	}
		
		public void prepend(Object x) 
		{
			Node latest = new Node(x);
			if(head == null)
			{
				head = latest;	
				tail = latest;	
			}
			else
			{
				head.prev = latest;	
				latest.next = head; 
				head = latest;
			}
		}
		public  void append(Object x) 
		{
			Node latest = new Node(x);
			if(head == null)
			{
				head = latest;
				tail = latest;
			}
			else
			{
				latest.prev = tail;
				tail.next = latest;
				tail = latest;
			}
		}
		public void clear() 
		{
			this.head = null;
			this.tail = null;
		}
		public void moveFront() 
		{
			if(isEmpty() == true)
			{
				
				return;		
			}
			cursor = this.head;
			cursor.next = this.head.next;
			cursor.prev = this.head.prev;
		}
		public  void moveBack() 
		{
			if(isEmpty() == true)
			{
				return;	
			}
			cursor = this.tail;
			cursor.next = this.tail.next;
			cursor.prev = this.tail.prev;
		}
		public void movePrev() 
		{
			if(cursor == null)
			{
				return;
			}
			else if(cursor == head)
			{
				cursor = null;
			}
			else
			{
				cursor = cursor.prev;
			}
		}
		public void moveNext() 
		{
			if(cursor == null)	
			{
				return;
			}
			else if(cursor == tail) 
			{
				cursor = null;
			}
			else if(cursor.next == null)
			{
				cursor = null;
			}
			else
			{
				cursor = cursor.next;
			}
		}
		public void insertBefore(Object x) 
		{
			if(isEmpty() == true)
			{
				System.err.println("Error: List is empty");
				System.exit(1);
			}
			else if(cursor == null)
			{
				System.err.println("Error: Cursor is undefined");
				System.exit(1);
			}
			else
			{
				if(cursor == head)
				{
					prepend(x);
				}
				else
				{
					Node latest = new Node(x);
					cursor.prev.next = latest;
					latest.prev = cursor.prev;
					cursor.prev = latest;
					latest.next = cursor;
					
				}
			}
		}
		public void insertAfter(Object x) 
		{
			if(isEmpty() == true)
			{
				System.err.println("Error: List is empty");
				System.exit(1);
			}
			else if(cursor == null)
			{
				System.err.println("Error: Cursor is undefined");
				System.exit(1);
			}
			else
			{
				if(cursor == tail)
				{
					append(x);
				}
				else
				{
					Node latest = new Node(x);
					cursor.next.prev = latest;
					latest.next = cursor.next;
					cursor.next = latest;
					latest.prev = cursor;
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
			if(cursor == head)
			{
				deleteFront();
			}
			else if(cursor == tail)
			{
				deleteBack();
			}
			else
			{
				cursor.next.prev = cursor.prev;
				cursor.prev.next = cursor.next;
				cursor.prev = null;
				cursor.next = null;
			}
		}
	
		public Object index() 
		{
			if(cursor == null)
			{
				return -1;
			}
			return cursor.nodeEntry;
		}
		public int length() 
		{
			if(isEmpty() == true)
			{
				return 0;
			}
			else
			{
				int count = 0;
				Node dummy = this.head;
				while(dummy != null)
				{
					count++;
					dummy = dummy.next;
				}
	            return count;
			}
		}
		public boolean isEmpty() 
		{
			if(this.head == null && this.tail == null)
			{
				return true;
			}
			return false;
		}
		public Object front() 
		{
			if(isEmpty() == true)
			{
				System.err.println("List is empty. Cannot return front.");
				System.exit(1);
			}
			return head.nodeEntry;
		}
		public Object back() 
		{
			if(isEmpty() == true)
			{
				System.err.println("List is empty. Cannot return back.");
				System.exit(1);
			}
			return tail.nodeEntry;
		}
		public Object getCursor()
		{
			return this.cursor;
		}
		public Object get()
		{
			if(this.cursor == null)
			{
				
				return null;
			}
			return this.cursor.nodeEntry;
		}

		public void traverse() 
		{
			Node dummy = this.head;
			while(dummy != null)
			{
				System.out.println("current node = "+dummy.nodeEntry);
				dummy = dummy.next;
			}
		}
		public List copyList(List r)
		{
			List curList = new List();
			curList = r;
			return curList;
		}
		
		
		public String toString()
		{
			
			
			Node dummy = this.head;
			String to = "";
			while(dummy != null)
			{
				to = to+dummy.nodeEntry.toString();
				to = to + "";
				dummy = dummy.next;
			}
			return to;
		}
		
}

