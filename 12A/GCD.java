/*
	Jason Bonilla 2016
	This program finds the Greatest Common Denominator between two numbers
	that the user selects. The program will refuse everything the user input
	unless it is a positive whole number.
	GCD.java
*/

import java.util.Scanner;
public class GCD
{
	public static void main(String[] args) 
    {
    	Scanner sc = new Scanner(System.in);
		int x = 0;
		int y = 0;
		int gcd;

		System.out.println("Enter a positive integer:");
		x = check(x,sc);
		System.out.println("Enter another positive integer:");
		y = check(y,sc);

		gcd = getGCD(x,y);
		System.out.println("The GCD of "+x+" and "+y+" is "+gcd);

	}
	//GCD using reccursion
	public static int getGCD(int a, int b)
	{
		if(b == 0)
		{
			return a;
		}
		return getGCD(b, a%b);
	} 
	//Ensures that the user enters a positive intiger 
	public static int check(int r, Scanner y)
	{
		while(true)
		{
			while(!y.hasNextInt())
			{
                y.next();
                System.out.println("Please enter a number");
				continue;
			}
			r= y.nextInt();
			if(r>0)
			{
				break;
			}
			System.out.println("Please enter a positive number");
		}
		return r;
	}
}
