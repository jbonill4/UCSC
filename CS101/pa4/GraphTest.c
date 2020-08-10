//-----------------------------------------------------------------
////Jason Bonilla
////jbonill4
////GraphTest.c
////------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.c"
#include "Graph.c"

int main()
{
	List lit = newList();
	prepend(lit,1);
	traverseList(lit);
	append(lit,2);
	traverseList(lit);
	printf("List working correctly moving onto Graph\n");
	Graph g = newGraph(3);
	printf("wassup\n");

   return 0;
}
