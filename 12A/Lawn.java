/*
   Jason Bonilla 2016
   This program takes in measurements for a lot and house. It then calculates
   how long it would take to mow the lawn for the given space assuming the 
   mowing is constant
*/
import java.util.Scanner;
public class Lawn
{
	public static void main(String[]args)
	{
		String hours = "hour";
		String minutes = "minute";
		String second = "second";
		double hLength;
		double hWidth;
		double length;
		double width;
		double lawnArea;
		double mowingRate;
		int h;//hours
		int m;//minutes
		int s;//seconds
      //initialize variables

      Scanner sc = new Scanner(System.in);
      System.out.println("Enter the length of the lot, in feet:");
      hLength = sc.nextDouble();
      System.out.println("Enter the width of the lot, in feet:");
      hWidth = sc.nextDouble();
      System.out.println("Enter the length of the house, in feet");
      length = sc.nextDouble();
      System.out.println("Enter the width of the house, in feet");
      width = sc.nextDouble();
      lawnArea = (hLength*hWidth)-(length*width);

      System.out.println("The lawn area is " +lawnArea+" square feet.");
      System.out.println("Enter the mowing rate, in square feet per second: ");

      mowingRate = sc.nextDouble();
      s = (int) Math.round(lawnArea/mowingRate);
      m = s/60;
      s = s%60; 
      h = m/60;
      m = m%60; 

      if(h>1)
      {
         hours = hours+ "s";
      }
      if(m>1)
      {
      	minutes= minutes + "s";
      }
      if(s>1)
      {
       second = second + "s";
      }
      System.out.println("The mowing time is "+h+" "+hours+" "+m+" "+ minutes+" "+" "+s+ " "+second);
   
   
	



	}



}

