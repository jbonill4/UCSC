
//-----------------------------------------------------------------
////Jason Bonilla
////jbonill4
////List.c
////------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#include "Graph.h"


typedef struct NodeObj{
	int value;
	struct NodeObj* next;
	struct NodeObj* prev;
}NodeObj; 


typedef NodeObj* Node;


typedef struct ListObj{
	Node head;
	Node tail;
	int indexx;
	int length;
	Node cursor;
}ListObj;

typedef ListObj* List;



Node createNewNode(int input)
{
	Node New = malloc(sizeof(NodeObj));
	New->value = input;
	New->prev = NULL;		
	New->next = NULL;
	return (New);
}

List createNewList(void)
{
	List list = malloc(sizeof(ListObj));;

	list->cursor = NULL;
	list->head = NULL;
	list->tail = NULL;
	list->indexx = 0; 
	list->length = 0;

	return(list);
}

void freeNode(Node* nodePt)
{
	if(*nodePt != NULL && nodePt !=  NULL)
	{
		free(*nodePt);

		*nodePt = NULL;
	}
	else
	{
		printf("Nothing happened\n");
	}
}
int empty(List cs)
{
	if(cs == NULL)
	{
		exit(1);
	}
	int empty = cs->length;
	return(empty == 0);
}

void freeList(List* ptr)
{
	if(ptr != NULL)
	{
		if(*ptr != NULL)
		{
			while(!empty(*ptr))
			{
				deleteFront(*ptr);
			}
			free(*ptr);
			*ptr = NULL;
		}
	}
}

int length(List list)
{
	if(list == NULL)
	{
		exit(1);
	}
	else
	{
		return(list->length);
	}
}

int indexx(List myList)
{
	if(empty(myList))
	{
		printf("List is empty\n");
		return -1;
	}
	else
	if(myList == NULL)
	{
		exit(1);
	}
	else
	if(myList->cursor == NULL)
	{
		return -1;
	}
	else
	{
		int count = 0;
		Node temp = myList->head;
		while(temp->value != myList->cursor->value)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
}

int front(List list)
{
	if(empty(list))	
	{
		exit(1);
	}
	else
	if(list == NULL)	
	{
		exit(1);
	}
	else
	{
		return list->head->value;
	}	
}

int back(List list)
{
	if(empty(list))	
	{
		exit(1);
	}
	else
	if(list == NULL)
	{
		exit(1);
	}
	else
	{
		return list->tail->value;
	}
}

int get(List list)
{
	if(list == NULL)
	{
		printf("list is null\n");
		exit(1);
	}
	else
	if(empty(list))
	{
		printf("list is   eefecwc\n");
		exit(1);
	}
	else
	if(indexx(list) < 0)
	{
		printf("index is less than 0\n");
		exit(1);
	}
	else
	{
		return list->cursor->value;
	}
}

int equals(List A, List B)
{
	int j = 0;
	if(length(A) == length(B))
	{
		Node node1 = A->head;
		Node node2 = B->head;

		for(int i = 0; i<length(A);i++)
		{
			if(node1->value == node2->value)
			{
				if((length(B)-1) == j)
				{
					return j;
				}
				else
				{
					node1 = node1->next;
					node2 = node2->next;
				}
			}
			else
			{
				return j;
			}
		}
	}
	return j;
}

void clear(List cur)
{
	if(cur == NULL)	
	{
		exit(1);
	}
	if(empty(cur))	
	{

	}
	else
	{
		cur->length = 0;
		while(!(empty(cur)))
		{
			deleteFront(cur);
		}
	}
}

void moveFront(List list)
{
	if(list == NULL)
	{
		exit(1);
	}
	else
	if(empty(list))	
	{

		
	}
	else
	{
		list->cursor = list->head;

		list->cursor->next = list->head->next;

		list->cursor->prev = list->head->prev;
	}
}

void moveBack(List L)
{
	if(L == NULL)
	{
		exit(1);
	}
	else
	if(empty(L))
	{
			
	}
	else
	{
		L->cursor = L->tail;

		L->cursor->next = L->tail->next;

		L->cursor->prev = L->tail->prev;
	}
}

void movePrev(List list)
{
	if(list == NULL)
	{
		exit(1);
	}
	else
	if(indexx(list) < 0)	
	{
		exit(1);
	}
	else
	if(list->cursor == list->head)	
	{
		list->cursor = NULL;
	}
	else
	{
		list->cursor = list->cursor->prev;
	}
}

void moveNext(List list)
{
	if(list == NULL)	
	{
		exit(1);
	}
	else
	if(indexx(list) < 0)
	{
		exit(1);	
	}
	else
	if(list->cursor == list->tail)
	{
		list->cursor = NULL;
	}
	else
	{
		list->cursor = list->cursor->next;
	}
}

void prepend(List list,  int data)
{
	Node newNode = createNewNode(data);

	if(list == NULL)
	{
		exit(1);
	}
	else
	if(empty(list))
	{
		list->head = newNode;
		list->tail = newNode;
		list->length = ++(list->length);

	}
	else
	{
		list->length = ++(list->length);

		list->head->prev = newNode;

		newNode->next = list->head;

		list->head = newNode;
	}
}

void append(List myList, int data)
{
	Node newNode = createNewNode(data);

	if(myList == NULL)	
	{
		exit(1);
	}
	else
	if(empty(myList))
	{
		
		myList->head = newNode;
		myList->tail = newNode;
		
		myList->length = ++(myList->length);
		
	}
	else
	{	
		
		
		myList->length = ++(myList->length);
		

		newNode->prev = myList->tail;

		myList->tail->next = newNode;

		myList->tail = newNode;
	}
}

void insertBefore(List list, int info)
{

	if(list == NULL)	
	{
		exit(1);
	}
	else
	if(empty(list))	
	{
		exit(1);
	}
	else
	if(indexx(list) < 0)
	{
		exit(1);
	}
	else
	if(list->cursor == list->head)
	{
		prepend(list, info);
		
	}
	else
	{
		Node newNode = createNewNode(info);

		list->cursor->prev->next = newNode;

		newNode->prev = list->cursor->prev;

		list->cursor->prev = newNode;

		newNode->next = list->cursor;
		
		list->length = ++(list->length);
		
	}	
}

void insertAfter(List list, int info)
{
	
	if(list == NULL)
	{
		return;
	}
	else
	if(empty(list))
	{
		return;
	}
	else
	if(indexx(list) < 0)
	{
		return;
	}
	else
	if(list->cursor == list->tail)
	{
		append(list, info);
		
		return;
	}
	else
	{
		Node newNode = createNewNode(info);

		list->cursor->next->prev = newNode;

		newNode->next = list->cursor->next;

		list->cursor->next = newNode;

		newNode->prev = list->cursor;
		
		list->length = ++(list->length);
		
	}	
}

void deleteFront(List lix)
{
	if(lix == NULL)	
	{
		exit(1);
	}
	else
	if(empty(lix))	
	{
		printf("Error!!\n");
			exit(1);
	}
	else
	{
		Node bro = lix->head;	
		if(length(lix) > 1)
		{
			lix->head = lix->head->next;	
			lix->head->prev = NULL;
		}
		else
		{
			lix->head = NULL;
			lix->tail = NULL;
		}

		lix->length--;
		freeNode(&bro);
	}	
}

void deleteBack(List myList)
{
	if(myList == NULL)	
	{
		exit(1);
	}
	else
	if(empty(myList))	
	{
		exit(1);
	}

	Node newNode = myList->tail;	
	if(length(myList) > 1)
	{
		myList->tail = myList->tail->prev;	
		myList->tail->next = NULL;
	}
	else
	{

		myList->head = NULL;
		myList->tail = NULL;
		myList->length--;
	}
	

	freeNode(&newNode);
}

void printList(FILE* in,List last)
{
	moveFront(last);
	int count = 0;
	
	while(count < length(last))
	{
		
		fprintf(in,"%d ", get(last));
		moveNext(last);
		count++;
		
	}
	fprintf(in,"\n");
	moveFront(last);
}
