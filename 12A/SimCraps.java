/*
	Jason Bonilla 2016
	This program asks the user for the number of trials for a game of Craps.
	Then simulates the winning percentage for the given amount of trials.

*/
import java.util.*;
public class SimCraps
{
	public static void main(String[]args)
	{
		//int wins;
		
		Scanner sc = new Scanner(System.in);
		System.out.println("How many trials?");
		double x = sc.nextDouble();
		System.out.println("Winning percentage: " + (NumWins(x))/x);
	}
	public static double NumWins(double r)
	{
		int toss1 = 0;
		int toss2 = 0;
		int result = 0;
		int point = 0;
		Random rand = new Random(1000);
		boolean wow = true;
		double wins = 0;
		for(int i = 0; i < r;i++)
		{
		    toss1 = rand.nextInt(6) + 1;
			toss2 = rand.nextInt(6) + 1;
			result = toss1 + toss2;
			if(result == 7 || result == 11)
			{
				wins++;
			}
			else
			{
				point = result;
				while(wow)
				{
					toss1 = rand.nextInt(6) + 1;
					toss2 = rand.nextInt(6) + 1;
					result = toss1 + toss2;
					if(result == 7)
					{
						wow = false;
					}
					else 
					if(result == point)
					{
						wins++;
						wow = false;
					}	
				}
				wow = true;
			}
		}
		return wins;
	}
}