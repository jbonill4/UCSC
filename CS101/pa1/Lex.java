/*---------------------------------------------------------------------------
   Jason Bonilla 2018
   Lex.java
---------------------------------------------------------------------------*/
import java.io.*;
import java.util.Scanner;
   
public class Lex {
   public static void main(String[] args) throws IOException{
     
      Scanner in = null;
      Scanner in2 = null;
      PrintWriter out = null;
      String line = null;
      String[] token = null;
      int i, n, lineNumber = 0;
      int count = 0;
      int temp = 0;
      List Now = new List();

      if(args.length < 2 || args.length > 2){
         System.err.println("Usage: Incorrect number of files");
         System.exit(1);
      }
      
      
      in = new Scanner(new java.io.File(args[0]));
      in2 = new Scanner(new java.io.File(args[0]));
      out = new PrintWriter(new java.io.FileWriter(args[1]));

      
      while( in.hasNextLine() )
      { 
         lineNumber++;
         line = in.nextLine()+" ";    
         token = line.split("\\s+");  
         n = token.length;
         for(i=0; i<n; i++){
            count++;
         }
      }

      
      String[] myStringArray = new String[count];

      
      while( in2.hasNextLine() )
      {
         line = in2.nextLine()+" ";    // add extra space so split works right
         token = line.split("\\s+");  // split line around white space
         n = token.length;
         for(i=0; i<n; i++)
         {
            myStringArray[temp]= token[i];
            temp++;         
         }   
      }
 
      Now.prepend(0);
      Now.moveFront();


      
      int arrLength = myStringArray.length;
      
      for(int r= 1;r<arrLength; r++)
      {
         String tempp = myStringArray[r]; 
          
          boolean t = true;
         while(t)
         {
            if(myStringArray[Now.cursor.index].compareTo(tempp)<0 && Now.cursor.prev == null)
            {
               
               Now.insertBefore(r);
               
              t = false;
            }
            else
            if(myStringArray[Now.cursor.index].compareTo(tempp)>0 && Now.cursor.next == null)
            {
               Now.insertAfter(r);
               
                t= false;
            }  
            else
            {
               Now.moveNext();
               if(myStringArray[Now.cursor.index].compareTo(tempp) >= 0)
               {
                  Now.insertBefore(r);
                  
                   t= false;
               }
            }
         }
         Now.moveFront(); 
         t= false;
      }
      
      while(Now.cursor != null)
      {
         out.println(myStringArray[Now.cursor.index]);
         Now.moveNext();
      }

      
      in.close();
      in2.close();
      out.close();
   }
}
