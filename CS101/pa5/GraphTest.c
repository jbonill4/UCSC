//-----------------------------------------------------------------
////Jason Bonilla
////jbonill4
////GraphTest.c
////PA5
////------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.c"
#include "List.c"

int main(int argc, char const *argv[])
{
	
	List x = createNewList();
	
	append(x,8);
	moveFront(x);
	insertBefore(x,2);
	insertAfter(x,3);
	int r = get(x);
	

	append(x,9);
	moveNext(x);
	
	append(x,10);
	moveNext(x);


	Graph test = newGraph(4);
	addArc(test,1,2);
	addArc(test,1,3);
	addArc(test,1,4);
	addArc(test,3,2);
	printf("Order is: %d \n",getOrder(test));
	printf("Size is: %d \n",getSize(test));
	printf("Source is: %d \n",getSource(test));
	int len = 1;
	
	printGraph(test);
	
	return 0;
}
