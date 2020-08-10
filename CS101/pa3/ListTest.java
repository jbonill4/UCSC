/*
	Jason Bonilla 2018
*/
public class ListTest
{	
	public class testObject
	{
		private int value;
		public testObject(){
		}
		public testObject(int val)
		{
			value = val;
		}
	}
	public static void main(String[] args) {
		List test = new List();
		String firstEntry = "first";
		String secEntry = "second";
		String thirEntry = "third";
		String forEntry = "fourth";
		String fivEntry = "fifth";
		
		System.out.println("Length of List is: "+ test.length());
		System.out.println("Checking if List is Empty: "+ test.isEmpty());
		test.prepend(firstEntry);											
		test.traverse();
		System.out.println("Length of List is: "+ test.length());
		System.out.println("Checking if List is Empty: "+ test.isEmpty());
		test.append(secEntry);												
		test.traverse();
		System.out.println("Length of List is: "+ test.length());
		System.out.println("Checking if List is Empty: "+ test.isEmpty());
		test.clear();														
		test.traverse();
		System.out.println("Length of List is: "+ test.length());
		System.out.println("Checking if List is Empty: "+ test.isEmpty());
		test.append(firstEntry);
		test.append(secEntry);
		test.append(thirEntry);
		test.traverse();
		test.moveFront();													
		test.moveNext();													
		test.insertBefore(forEntry);												
		System.out.println("Length of List is: "+ test.length());
		System.out.println("Checking if List is Empty: "+ test.isEmpty());
		test.moveBack();													
		test.insertBefore(fivEntry);
		test.toString();
		test.traverse();


	}
}
