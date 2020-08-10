/*
  Jason Bonilla 2016
  This program is a guessing game with the user. The user has three tries
  to guess a 'random' number between 1 and 10.
*/

import java.util.Scanner;
public class Guess
{
   public static void main(String[] args) 
   {
      Scanner sc = new Scanner(System.in);
      int answer = (int)((Math.random()*9)+1);
      int guess;
      boolean x = false;
      System.out.println("\nI'm thinking of an integer in the range 1 to 10."+ 
      " You have three guesses.");

      //the user enters first guess
      System.out.print("\nEnter your first guess: ");
      guess = sc.nextInt();
      check(guess,answer);
      //if the guess is incorrect the user will have up to 2 more tries
      if(guess != answer)
      {
        System.out.print("Enter your second guess: ");
        guess = sc.nextInt();
        check(guess,answer); 
      }
      if(guess != answer)
      {
        System.out.print("Enter your third guess: ");
        guess = sc.nextInt();
        check(guess,answer);
      }
      if(guess != answer)
      {
      	System.out.println("You lose. The number was "+answer+".");
      	System.out.println();
      }
	}
  
  //this fuction checks to see if the guess is correct
	public static void check(int attempt, int answer)
	{
        if(attempt == answer)
       {
    	System.out.println("You win!");
    	System.out.println();
       }
       else
       if(attempt < answer)
       {
        System.out.println("Your guess is too low.");
        System.out.println();
       }
       else
       if(attempt > answer)
       {
       System.out.println("Your guess is too high.");
       System.out.println();
       }
	}
}