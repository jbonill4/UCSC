/*
	Jason Bonilla 2018
	Linked List
*/
#include<stdio.h>
#include <stdlib.h>
#include "List.h"

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
struct List{
	struct Node* head;
	struct Node* tail;
	struct Node* index;
};
struct List* newList()
{
	struct List* newList = (struct List*)malloc(sizeof(struct List));
	newList->head = NULL;
	newList->tail = NULL;
	newList->index = NULL;
	return newList;
}
void freeList(struct List *tempList)
{
	clear(tempList);
	tempList = NULL;
}
struct Node* GetNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode; 
};

int length(struct List *tempList)
{
	struct Node* temp = tempList->head;
	int count = 0;
	if(temp == NULL)
	{
		return count;
	}
	while(temp->next != NULL)
	{
		count = count +1;
		temp = temp->next;
	}
	return count;
}

int indexx(struct List *tempList)
{
	if(tempList->index != NULL)
	{
		if(tempList->index->data > -1)
		{
			return tempList->index->data;
		}
	}
	return -1;
}

int front(struct List *tempList)
{
	if(tempList->head == NULL)
	{
		printf("NULL\n");
		return 0;
	}
	else
	{
		return tempList->head->data;
	}	
}

int back(struct List *tempList)
{
	if(tempList->tail == NULL)
	{
		printf("NULL\n");
		return 0;
	}
	else
	{
		return tempList->tail->data;
	}	
}

int get(struct List *tempList)
{
	if(tempList->index != NULL)
	{
		if(tempList->index->data >0)
		{

		}
		return tempList->index->data;
	}
	else
		return -1;
}
int equals(struct List *tempList, struct List *tempList2) 
{
	int equal = 1;
	if(length(tempList) == length(tempList2))
	{
		struct Node* temp1 = tempList->head;
		struct Node* temp2 = tempList2->head;
		while(temp1 != NULL && temp2 != NULL)
		{
			if(temp1->data != temp2->data)
			{
				equal = 0;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	else
	{
		equal = 0;
	}
	if(equal == 0)
	{
		printf("THEYRE NOT EQUAL\n");
		return -1;
	}
	printf("THEYRE EQUAL\n");
	return 1;
}

void clear(struct List *tempList)
{
	struct Node* temp = tempList->head;
	struct Node* following;
	while(temp != NULL)
	{
		following = temp->next;
		free(temp);
		temp = following;
	}
	tempList->head = NULL;
	tempList->tail = NULL;
	tempList->index = NULL;
	
}

void moveFront(struct List *tempList)
{
	struct Node* temp = tempList->head;
	if(length(tempList) != 0)
	{
		tempList->index = tempList->head;
	}
}

void moveBack(struct List *tempList)
{
	moveTail(tempList);
	if(length(tempList) != 0)
	{
		tempList->index = tempList->tail;
	}
}

void movePrev(struct List *tempList)
{
	struct Node* temp = tempList->index;
	if(length(tempList) != 0)
	{
		if(temp->prev != NULL)
		{
			tempList->index = temp->prev;
		}
	}
}

void moveNext(struct List *tempList)
{
	struct Node* temp = tempList->index;
	if(length(tempList) != 0)
	{
		if(temp->next != NULL)
		{
			tempList->index = temp->next;
		}
	}
}

void prepend(struct List *tempList, int data)
{
	struct Node* newNode = GetNewNode(data);
	if (tempList->head == NULL)
	{
		tempList->head = newNode;
		tempList->tail = newNode;
		tempList->index = newNode;
		return;
	}
	tempList->head->prev= newNode; 
	newNode->next = tempList->head; 
	tempList->head = newNode; 
	moveTail(tempList);
}

void append(struct List *tempList, int data)
{
	struct Node* newNode = GetNewNode(data);
	struct Node* temp = tempList->head;
	if(temp == NULL)
	{
		
		return;
	}
	while(temp->next != NULL)
	{
		
		temp = temp->next;
	}
	
	temp->next= newNode;
	newNode->prev = temp;
	
	moveTail(tempList);
}

void insertBefore(struct List *tempList,int data)
{
	struct Node* newNode = GetNewNode(data);
	struct Node* tempNode;
	if(length(tempList) != 0)
	{
		if(tempList->index != NULL)
		{
			if(tempList->index->prev != NULL)
			{
				tempNode = tempList->index->prev;
				newNode->next = tempList->index;
				tempNode->next = newNode;
				tempList->index->prev = newNode;
				newNode->prev = tempNode;
			}
		}
	}
}

void insertAfter(struct List *tempList,int data)
{
	struct Node* newNode = GetNewNode(data);
	struct Node* tempNode;
	if(length(tempList) != 0)
	{
		if(tempList->index != NULL)
		{
			if(tempList->index->next != NULL)
			{
				tempNode = tempList->index->next;
				newNode->prev = tempList->index;
				tempNode->prev = newNode;
				tempList->index->next = newNode;
				newNode->next = tempNode;
			}
		}
	}	
}

void deleteFront(struct List *tempList)
{
	struct Node* tempNode;
	if(length(tempList) > -1)
	{
		if(tempList->head != NULL)
		{
			if(tempList->head->next != NULL)
			{
				tempNode = tempList->head->next;
				tempNode->prev = NULL;
				free(tempList->head);
				tempList->head = tempNode;
			}
			else
			{
				tempList->head = NULL;
				free(tempList->head);
			}
		}
	}
}

void deleteBack(struct List *tempList)
{
	struct Node* tempNode;
	if(length(tempList) > -1)
	{
		if(tempList->tail != NULL)
		{
			if(tempList->tail->prev != NULL)
			{
				
				tempNode = tempList->tail->prev;
				tempNode->next = NULL;
				
				free(tempList->tail);
				tempList->tail = NULL;
				
				tempList->tail = tempNode;
			}
			else
			{
				tempList->tail = NULL;
				free(tempList->tail);
			}
		}
	}
}

void delete(struct List *tempList)
{
	if(length(tempList) >-1)
	{
		struct Node* tempNode = tempList->index;
		if(tempNode->prev != NULL && tempNode->next != NULL)
		{
			struct Node* tempNextNode = tempNode->next;
			struct Node* tempPrevNode = tempNode->prev;
			tempNextNode->prev = tempNode->prev;
			tempPrevNode->next = tempNode->next;
			tempNode = NULL;
			free(tempNode);
			
		}
		else
		if(tempNode->next == NULL)
		{
			
			deleteFront(tempList);
		}
		else
		if(tempNode->prev == NULL)
		{
			deleteBack(tempList);
		}
	}	
}

void moveTail(struct List *tempList)
{
	struct Node* temp = tempList->head;
	if(temp == NULL)
	{
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	tempList->tail = temp; 
}

void printList(struct List *tempList)
{
	struct Node* temp = tempList->head;
	printf("Printing forward: ");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void PrintReverse(struct List *tempList)
{
	struct Node* temp = tempList->head;
	if(temp == NULL)//CHECKS IF NULL
		return;

	while(temp->next != NULL) //GOES TO LAST NODE
	{
		temp = temp->next;
	}
	printf("Printing in reverse: ");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

