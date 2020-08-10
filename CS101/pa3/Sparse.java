/*
   Jason Bonilla 2018
*/

import java.io.*;
import java.util.Scanner;
   
public class Sparse {
   public static void main(String[] args) throws IOException{

      
      Scanner in = null;
      Scanner in2 = null;
      PrintWriter out = null;
      String line = null;
      String[] token = null;
      int i, n, lineNumber = 0;
      int count = 0;
      int temp = 0;
      int sizeofMatrix = 0;
      int sizeofA = 0;;
      int sizeofB = 0;;
      int curRow;
      int curCol;
      double value;
      int counter = 1;
      String entryParser;
    
      if(args.length < 2 || args.length > 2){
         System.err.println("Usage: Incorrect number of files");
         System.exit(1);
      }

      in = new Scanner(new java.io.File(args[0]));
      out = new PrintWriter(new java.io.FileWriter(args[1]));

      if(in.hasNextLine() )
      {
         line = in.nextLine() +" ";
         token = line.split("\\s+");

         String intParser = token[0];
         sizeofMatrix = Integer.parseInt(intParser);
         intParser = token[1];
         sizeofA = Integer.parseInt(intParser);
         intParser = token[2];
         sizeofB = Integer.parseInt(intParser);

         
      }
      out.println("");
      
      Matrix a = new Matrix(sizeofMatrix);
      Matrix b = new Matrix(sizeofMatrix);
      String test1;
      String test2;
      
      if(in.hasNextLine())
      {
         line = in.nextLine() +" ";
         if (in.hasNextLine())
         {
            while(counter <= sizeofA)
            {
               
               line = in.nextLine() +" ";  
               token = line.split("\\s+");
               if(!(token.equals(" ")))
               {
                  entryParser =  token[0];
                  curRow = Integer.parseInt(entryParser);
                  entryParser =  token[1];
                  curCol = Integer.parseInt(entryParser);
                  entryParser =  token[2];
                  value = Double.parseDouble(entryParser);
                  a.appendToMatrix(curRow-1,curCol,value);
                  counter++;
               }
               
               
               
            
            }
         }
      }
      out.println("A has " +a.getNNZ()+ " non-zero entries");
      test1 =a.toString();
      out.println(test1);
      
      counter = 1;
      
      if(in.hasNextLine())
      {
         line = in.nextLine() +" ";
         if (in.hasNextLine())
         {
            while(counter <= sizeofB)
            {
               
               line = in.nextLine() +" ";  
               token = line.split("\\s+");
               if(!(token.equals(" ")))
               {
                  entryParser =  token[0];
                  curRow = Integer.parseInt(entryParser);
                  entryParser =  token[1];
                  curCol = Integer.parseInt(entryParser);
                  entryParser =  token[2];
                  value = Double.parseDouble(entryParser);
                  
                  b.appendToMatrix(curRow-1,curCol,value);
                  counter++;
               }
               
               
               
            
            }
         }
      }  
      out.println("B has "+b.getNNZ()+" non-zero entries:");
      test1 = b.toString();
      out.println(test1);
      out.println();
     
      Matrix add = a.Copy();
      add.toString();
      out.println("(1.5)*A =");
      add.scalarMult(1.5);
      test1 = add.toString();
      out.println(test1);
    
      out.println("A+B =");
      Matrix a1 = a.Copy();
      Matrix b1 = b.Copy();
      Matrix sum = a1.add(b1);
      test1 = sum.toString();
      out.println(test1);
     
      out.println("A+A =");
      Matrix a2 = a.Copy();
      Matrix a3 = a.Copy();
      Matrix sum1 = a2.add(a3);
      test1 =sum1.toString();
      out.println(test1);
     
      out.println("B-A =");
      Matrix a4 = a.Copy();
      Matrix b2 = b.Copy();
      Matrix difference =b2.sub(a4);
      test1 =difference.toString();
      out.println(test1);
     
      out.println("A-A =");
      Matrix a5 = a.Copy();
      Matrix a6 = a.Copy();
      Matrix difference2 = a5.sub(a6);
      test1 =difference2.toString();
      out.println(test1);
      
      out.println("Transpose(A) =");
      Matrix a7 = a.Copy();
      Matrix newTrans = a7.transpose();
      test1 =newTrans.toString();
      out.println(test1);
      
      out.println("A*B =");
      Matrix a8 = a.Copy();
      Matrix b3 = b.Copy();
      Matrix x = a8.mult(b3);
      test1 =x.toString();
      out.println(test1);
      
      out.println("B*B =");
      Matrix b4 = b.Copy();
      Matrix b5 = b.Copy();
      Matrix s = b4.mult(b5);
      test1 =s.toString();
      out.println(test1);
     



      in.close();
      out.close();
   }
}
