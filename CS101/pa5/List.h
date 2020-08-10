#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LIST_A_INCLUDE
#define LIST_A_INCLUDE

typedef struct ListObj* List;
List createNewList(void);

void freeList(List* listPtr);

int length(List list);
int indexx(List list);

int front(List list);
int back(List list);

int get (List list);
int empty(List cs);

int equals(List A, List B);
void clear(List list);

void moveFront (List list);
void moveBack(List list);

void movePrev(List list);
void moveNext(List list);

void prepend(List list, int data);
void append(List list, int data);

void insertBefore(List list, int data);
void insertAfter(List list, int data);

void deleteFront(List list);
void deleteBack(List list);

void printList(FILE* in,List last);

#endif
