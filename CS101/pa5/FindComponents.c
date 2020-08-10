//-----------------------------------------------------------------
////Jason Bonilla
////jbonill4
////FindComponents.c
////------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "Graph.c"
#include "List.c"

int concat(char one, char two)
{
	int temp1 = one - '0';					
	temp1 = temp1*10;						
	
	int temp2 = two - '0';					
	
	int result = temp1 + temp2;				
	
	return result;
}


int main(int argc, char **argv)
{
	FILE *fp;
	FILE *sp;
	char ch;
	char size1;
	char size2;
	int actualSize;
	char firstNum;
	char firstNum2;
	int actualFirst;
	char secondNum;
	char secondNum2;
	int actualSecond;
	char space = 32;
	char newline = 10;

	fp = fopen(argv[1], "r");	
	sp = fopen(argv[2],"w");

	if(argc != 3)
  	{
   		printf("Incorrect number of files\n");
  	 	exit(0);
 	}
	if(fp == NULL)
	{
		printf("Could not open the first file\n");
		exit(0);
	}
	if(sp == NULL)
	{
		printf("Could not open the second file to write\n");
		exit(0);
	}			
	ch = fgetc(fp);																
	size1 = ch;																	
	actualSize = ch - '0';														
	ch = fgetc(fp); 															
	if(ch != newline)															
	{
		size2= ch;
		actualSize = concat(size1,size2);
		ch = fgetc(fp);
	}

	fprintf(sp, "Adjacency list representation of G: \n" );
	
	Graph G = newGraph(actualSize);
	while((ch = fgetc(fp)) != EOF )												
	{
		firstNum = ch;															
		actualFirst = firstNum - '0';											
		ch = fgetc(fp);															
		if(ch != space)
		{
			firstNum2 = ch;														
			actualFirst = concat(firstNum,firstNum2);
			ch = fgetc(fp);														
			ch = fgetc(fp);														
			secondNum = ch;														
			actualSecond = secondNum - '0';										
			ch = fgetc(fp);														
			if(ch != newline)
			{
				secondNum2 = ch;
				actualSecond = concat(secondNum,secondNum2);
				ch = fgetc(fp);													
			}
		}
		else
		{
			ch = fgetc(fp);														
			secondNum = ch;														
			actualSecond = secondNum - '0';										
			ch = fgetc(fp);														
			if(ch != newline)
			{
				secondNum2 = ch;
				actualSecond = concat(secondNum,secondNum2);					
				ch = fgetc(fp);													
			}
			if(firstNum == 48 && secondNum == 48)								
			{
				break;
			}
		}

		
		addArc(G,actualFirst,actualSecond);
		
		if(ch == EOF)
		{
			fprintf(sp, "END OF FILE\n" );
			exit(0);
		}

	}
	printGraph(sp,G);
	
	fprintf(sp, "\n" );
	fprintf(sp, "G contains ? strongly connected components:\n" );

	free(G);	
	fclose(fp);
	fclose(sp);
	return 0;

}

