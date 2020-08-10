//-----------------------------------------------------------------
////Jason Bonilla
////jbonill4
////List.c
////------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
typedef struct NodeObj{
	int element;
	struct NodeObj* next;
	struct NodeObj* prev;
}NodeObj; 

typedef NodeObj* Node;
	
typedef struct ListObj{
	Node head;
	Node tail;
	int listindexx;
	int length;
	Node cursor;
}ListObj;

Node newNode(int data)
{
	Node New = malloc(sizeof(NodeObj));
		New->element = data;
			New->prev = NULL;		
				New->next = NULL;
					return (New);
}
List newList(void)
{
	List Lis;
	Lis = malloc(sizeof(ListObj));

	Lis->cursor = NULL;
		Lis->head = NULL;
			Lis->tail = NULL;
				Lis->listindexx = 0; 
					Lis->length = 0;

	return(Lis);
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
int isEmpty(List cs)
{
	if(cs == NULL){
		printf("Error! list empty\n");
			exit(1);
	}

	return(cs->length == 0);
}
void freeList(List* ptr)
{
	if(ptr != NULL && *ptr != NULL){
		while(!isEmpty(*ptr)){
			deleteFront(*ptr);
		}

		free(*ptr);
			*ptr = NULL;
	}
}
int equals(List A, List B)
{
	int i = 0;
	if(length(A) == length(B)){
		Node node1 = NULL;
			Node node2 = NULL;

		node1 = A->head;
			node2 = B->head;

		for(i = 0; i<length(A);i++){
			if(node1->element == node2->element){
				if(i == (length(A)-1)){
					return 1;
				}
				else{
					node1 = node1->next;
						node2 = node2->next;
				}
			}
			else{
				return 0;
			}
		}
	}
	return 0;
}
int indexx(List L)
{
	if(L == NULL){
		printf("Error!\n");
		exit(1);
	}
	if(isEmpty(L)){
		return -1;
	}
	if(L->cursor == NULL){
		return -1;
	}
	else {
		int count = 0;
			Node temp = L->head;
		while(temp->element != L->cursor->element){
			count++;
			temp = temp->next;
		}
		return count;
	}
}
int get(List list)
{
	if(list == NULL)	{
		printf("Error!\n");
		exit(1);
	}
	if(isEmpty(list)){
		printf("Error!!\n");
		exit(1);
	}
	if(indexx(list)<0)	{
		printf("Error!!!\n");
		exit(1);
	}
	else
	{
		return list->cursor->element;
	}
}
int length(List list)
{
	if(list == NULL){
		printf("Error: = length() on a NULL List reference\n");
			exit(1);
	}

	return(list->length);
}
int front(List list)
{
	if(list == NULL)	{
		printf("Error!\n");
			exit(1);
	}
	if(isEmpty(list))	{
		printf("Error!! \n");
			exit(1);
	}
	return (list->head->element);
}
int back(List list)
{
	if(list == NULL)	{
		printf("Error! \n");
			exit(1);
	}
	if(isEmpty(list))	{
		printf("Error!\n");
			exit(1);
	}
	return (list->tail->element);
}
void deleteBack(List L)
{
	Node newNode = NULL;

	if(L == NULL)	{
		printf("Error! \n");
			exit(1);
	}
	if(isEmpty(L))	{
		printf("Error!! \n");
			exit(1);
	}

	newNode = L->tail;	
	if(length(L) > 1){

		L->tail = L->tail->prev;	
			L->tail->next = NULL;
	}
	else{

		L->head = NULL;
			L->tail = NULL;
	}
	L->length--;

	freeNode(&newNode);
}
void deleteFront(List lix)
{
	Node bro = NULL;	
	if(lix == NULL)	{
		printf("Error!\n");
			exit(1);
	}

	if(isEmpty(lix))	{
		printf("Error!!\n");
			exit(1);
	}

	bro = lix->head;	
	if(length(lix) > 1){
		lix->head = lix->head->next;	
			lix->head->prev = NULL;
	}
	else{
		lix->head = NULL;
			lix->tail = NULL;
	}

	lix->length--;
	freeNode(&bro);
}
void insertAfter(List L, int info)
{
	
	if(L == NULL)	{

		printf("Error!\n");
		exit(1);
	}
	if(isEmpty(L))	{

		printf("Error!!\n");
		exit(1);
	}
	if(indexx(L) < 0){

		printf("Error!!!\n");
		exit(1);
	}
	if(L->cursor == L->tail){

		append(L, info);
			return;
	}
	else{
		Node newNod = newNode(info);
		L->cursor->next->prev = newNod;
		newNod->next = L->cursor->next;
		L->cursor->next = newNod;
		newNod->prev = L->cursor;
	}
	L->length++;
}
void insertBefore(List L, int info)
{

	if(L == NULL)	{
		printf("Error!\n");
			exit(1);
	}
	if(isEmpty(L))	{
		printf("Error!!\n");
			exit(1);
	}
	if(indexx(L) < 0){
		printf("Error!!!\n");
			exit(1);
	}
	if(L->cursor == L->head){
		prepend(L, info);
		return;
	}
	else{
		Node newNod = newNode(info);
			L->cursor->prev->next = newNod;
				newNod->prev = L->cursor->prev;
					L->cursor->prev = newNod;
						newNod->next = L->cursor;
	}

	L->length++;
}
void append(List L, int data)
{
	Node newNod;
		newNod = newNode(data);

	if(L == NULL)	
	{
		printf("Error!\n");
			exit(1);
	}
	if(isEmpty(L)){

		L->head = newNod;
			L->tail = newNod;
	}
	else{
		
		newNod->prev = L->tail;
			L->tail->next = newNod;
				L->tail = newNod;
	}

	L->length++;
}
void prepend(List list,  int data)
{
	Node newNod = newNode(data);
	if(list == NULL){
		printf("Error!\n");
			exit(1);
	}
	if(isEmpty(list)){
		list->head = newNod;
			list->tail = newNod;
	}
	else{
		list->head->prev = newNod;
			newNod->next = list->head;
				list->head = newNod;
	}

	list->length++;
}
void movePrev(List list)
{
	if(list == NULL)	{
		printf("Error!\n");
			exit(1);
	}
	if(indexx(list) < 0)	{
		return;		
	}
	if(list->cursor == list->head)	{
		list->cursor = NULL;
	}
	else{
		list->cursor = list->cursor->prev;
	}

}
void moveNext(List list)
{
	if(list == NULL)	{
		printf("Error!\n");
			exit(1);
	}
	if(indexx(list) < 0)	{

		printf("less than 0 buddy\n");
		return;		
	}

	if(list->cursor == list->tail)	{
		list->cursor = NULL;
	}
	else{
		list->cursor = list->cursor->next;
	}
}
void moveBack(List L)
{
	if(L == NULL)	{
		printf("Error!\n");
			exit(1);
	}
	if(isEmpty(L))	{

		printf("EMPTY\n");
			return;		
	}
	else{
		L->cursor = L->tail;
			L->cursor->next = L->tail->next;
				L->cursor->prev = L->tail->prev;
	}
}
void moveFront(List list)
{
	if(list == NULL){
		printf("Error! \n");
			exit(1);
	}
	if(isEmpty(list) )	{

		return;		
	}
	else{
		list->cursor = list->head;
			list->cursor->next = list->head->next;

				list->cursor->prev = list->head->prev;
	}

}
void clear(List cur)
{
	if(cur == NULL)	{
		printf("Error!\n");
		exit(1);
	}
	if(isEmpty(cur))	{
		return;
		printf("EMpty!\n");
	}
	else{
		while(!isEmpty(cur)){
			deleteFront(cur);
		}

		cur->length = 0;

		return;
	}
}
List copyList(List list)
{
	int i = 0;
		int j = length(list);
			List A1 = newList();
				Node curNode = NULL;
					curNode = list->head;
	for(i=0;i<j;i++){
		append(A1, curNode->element);
			curNode = curNode->next;
	}
	return (A1);
}
int traverseList(List free)
{
	Node current = NULL;

	if(free == NULL)	{
		printf("Error!\n");
			exit(1);
	}
	if(isEmpty(free))	{
		printf("Error!!\n");
			exit(1);
	}
	current = free->head;

	while(current != NULL){

		printf("cur node: %d\n",current->element);

			current = current->next;
	}

	return 0;
}
