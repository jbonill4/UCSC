//-----------------------------------------------------------------
////Jason Bonilla
////jbonill4
////Graph.c
////------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Graph.h"
#include "List.h" 

#define NIL -1	  
#define INFINITY -2

typedef struct GraphObject
{
	List *adjacentArray;	
	List queue;	
	int *discover;
	int *finish;
	int *color;			
	int order;		
	int size;		
	int realIndex; 	
	int *parent;	
}GraphObject;

Graph newGraph(int n)
{
	Graph startG = malloc(sizeof(GraphObject));
	startG->adjacentArray = malloc(sizeof(List*)*n+1);
	startG->color = (int*)malloc(sizeof(int)*(n+1));
	startG->discover = (int*)malloc(sizeof(int)*(n+1));
	startG->finish = (int*)malloc(sizeof(int)*(n+1));
	startG->parent = (int*)malloc(sizeof(int)*(n+1));
	startG->order = n;
	startG->size = 0;
	for(int i = 1;i<n+1;i++)
	{
		startG->finish[i] = -2;
		startG->discover[i] = -1;
		startG->adjacentArray[i] = createNewList();
		startG->color[i] = 3;
		startG->parent[i] = NIL;
	}
	return (startG);
}

int getOrder(Graph G)
{
	return G->order;
}
Graph getGraph(Graph curGraph)
{
	return curGraph;
}
int getSize(Graph curGraph)
{
	return curGraph->size;
}
int getParent(Graph curGraph, int data)
{
	if(data > getOrder(curGraph))
	{
		printf("data is greater than order\n");
		return -1;
	}
	else
	if(data < 1)
	{
		printf("data is less than 1\n");
		return -1;
	}
	return curGraph->parent[data];
}
int getDiscover(Graph G, int u)
{
	if(u > getOrder(G))
	{
		printf("asking for is greater than order\n");
		return -1;
	}
	else
	if(u < 1)
	{
		printf("asking for is less than 1\n");
		return -1;
	}
	return G->discover[u];
}
int getFinish(Graph G, int u)
{
	if(u > getOrder(G))
	{
		printf("asking for is greater than order\n");
		return -1;
	}
	else
	if(u < 1)
	{
		printf("asking for is less than 1\n");
		return -1;
	}
	return G->finish[u];
}
void freeGraph(Graph* curGraph)
{
	int tempCount = (getOrder(*curGraph))+1;
	Graph hold;
	if(tempCount > -1)
	{
		Graph hold = getGraph(*curGraph);
		if(curGraph != NULL)
		{
			if(*curGraph != NULL)
			{
				for(int j=1;j<tempCount;j++)
				{
					freeList(&hold->adjacentArray[j]);									
				}
			}
		}
	}
	free(hold->parent);
	hold->parent = NULL;
	free(hold->color);
	hold->color = NULL;
	free(hold->queue);
	hold->queue = NULL;
	free(*curGraph);
	*curGraph = NULL;
}
void addEdge(Graph temp, int one, int two)
{
	int first;
	int second;
	first = 0;
	second = 0;
	int ord = getOrder(temp);
	int i;
	if(temp == NULL)
	{
		printf("graph is null!\n");
		return;
	}
	else
	if(one == two)
	{
		return;
	}
	else
	if(one < 1)
	{
		return;
	}
	else
	if(two < 1 )
	{
		return;
	}
	else
	if(one > ord)
	{
		printf("Error3!\n");
		return;
	}
	else
	if(two > ord)
	{
		printf("Error3!\n");
		return;
	}
	else
	{
		if(empty(temp->adjacentArray[two]))
		{
			first = 1;
			temp->size = (temp->size)++;
			append(temp->adjacentArray[two], one);
		}
		if(empty(temp->adjacentArray[one]))
		{
			second = 1;
			temp->size = (temp->size)++;
			append(temp->adjacentArray[one], two);
			
		}
		if(second == 0)
		{
			moveFront(temp->adjacentArray[one]);
			if(second == 0 && 1)
			{
				for(i =0;i <length(temp->adjacentArray[one]);i++)
				{
					int hold = get(temp->adjacentArray[one]);
					int lenghold = length(temp->adjacentArray[one]); 
					if(two< hold)
					{
						insertBefore(temp->adjacentArray[one], two);
						temp->size = (temp->size)++;
						second = 1;
						break;
					}
					else
					if(two == hold)
					{
						second = 1;
						break;
					}
					else 
					if(two == lenghold-1)
					{
						insertAfter(temp->adjacentArray[one], two);
						temp->size = (temp->size)++;
						second = 1;
						break;
					}
					else
					{
						moveNext(temp->adjacentArray[one]);
					}
				}	
			}
		
		}
		if(first == 0)
		{
			moveFront(temp->adjacentArray[two]);
			if(first == 0 && 1)
			{
				int hold2 = get(temp->adjacentArray[two]);
				int lenghold2 = length(temp->adjacentArray[two]);

				for(i=0; i<length(temp->adjacentArray[two]);i++)
				{
					if(one < hold2)
					{
						insertBefore(temp->adjacentArray[two], one);
						temp->size = (temp->size)++;
						first = 1;
						break;			
					}
					else
					if(one == hold2)
					{
						first = 1;
						break;			
					}
					else 
					if( two == lenghold2-1 )
					{
						insertAfter(temp->adjacentArray[two], one);
						temp->size = (temp->size)++;
						first = 1;
						break;
					}
					else
					{
						moveNext(temp->adjacentArray[two]);
					}
				}
			}
		
		}
	}
}
void addArc(Graph cGraph, int num1, int num2)
{
	if(cGraph == NULL)
	{
		return;
	}
	else
	if(num2 > getOrder(cGraph))
	{
		printf("You messed up buddy!\n");
		return;
	}
	else
	if(num2 < 1)
	{
		printf("You messed up buddy!\n");
		return;
	}
	else
	if(num1 > getOrder(cGraph))
	{
		printf("You messed up buddy!\n");
		return;
	}
	else
	if(num1 < 1)
	{
		printf("You messed up buddy!\n");
		return;
	}
	else
	if(1 && empty(cGraph->adjacentArray[num1]))
	{

		append(cGraph->adjacentArray[num1], num2);
		cGraph->size = ++(cGraph->size);
		return;
	}
	else
	{
		moveFront(cGraph->adjacentArray[num1]);
		for(int i =0; i <length(cGraph->adjacentArray[num1]);i++)
		{
			int curNum = get(cGraph->adjacentArray[num1]);
			int curLength = length(cGraph->adjacentArray[num1]);

			if(num2 == curNum)
			{
				append(cGraph->adjacentArray[num1], num2);
				cGraph->size = ++(cGraph->size);
				return;
			}
			else 
			if(num2 < curNum)
			{
				insertBefore(cGraph->adjacentArray[num1], num2);
				cGraph->size = ++(cGraph->size);
				return;
			}
			else 
			if(i == curLength-1)
			{
				insertAfter(cGraph->adjacentArray[num1], num2);
				cGraph->size = ++(cGraph->size);
				return;
			}
			else
			moveNext(cGraph->adjacentArray[num1]);			
		}
	}
}
void printGraph(FILE* out ,Graph test)
{
	for (int i = 1; i < getOrder(test)+1; i++)
	{
		if(length(test->adjacentArray[i]) > 0)
		{

			fprintf(out,"%d: ",i);
			printList(out,test->adjacentArray[i]);
		}
		else
		{
			fprintf(out,"%d: ",i);
			fprintf(out,"\n" );
		}
	}
}
void makeNull(Graph temp)
{
	if (temp != NULL)
	{
		for(int i =1;i < temp->realIndex;i++)
		{
			clear(temp->adjacentArray[i]);
		}
	}
	else
	{
		printf("GRAPH IS NULL\n");
	}	
}


