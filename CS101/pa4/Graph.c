//----------------------------------------------------------------------
////Jason Bonilla
////jbonill4
////Pa4
//Graph.c
////----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "List.h" 

#define WHITE -3
#define GRAY -4
#define BLACK -5
#define NIL -1	  
#define INF -2

typedef struct GraphObj
{
	List *adjArray;	
		List queue;	
			int source;	
				int *color;			
					int order;		
						int size;		
							int rIndex; 	
								int *parent;	
									int *distance;
}GraphObj;

Graph newGraph(int n)
{
	Graph startG = malloc(sizeof(GraphObj));
	startG->adjArray = malloc(sizeof(List*)*n+1);
	startG->queue = newList();
	startG->order = n;
	startG->size = 0;
	startG->source = NIL;
	startG->rIndex = n+1;
	startG->color = (int*)malloc(sizeof(int)*(n+1));
	startG->parent = (int*)malloc(sizeof(int)*(n+1));
	startG->distance = (int*) malloc(sizeof(int)*(n+1));
		
							

	

	for(int i = 1;i<n+1;i++){
		startG->adjArray[i] = newList();
			startG->color[i] = WHITE;
				startG->parent[i] = NIL;
					startG->distance[i] = INF; 
	}
	return (startG);
}
int getrIndex(Graph gr){
	return gr->rIndex;
}
Graph getGraph(Graph gr){
	return gr;
}
void freeGraph(Graph* temp)
{
	int tempcount = getrIndex(*temp);
	Graph temp = getGraph(*temp);
	if(temp != NULL && *temp != NULL){
		for(int i=1;i<tempcount;i++){
			freeList(&temp->adjArray[i]);									
		}
	}

	free(temp->parent);
		free(temp->color);
			free(temp->distance);
				free(temp->queue);
	temp->parent = NULL;
		temp->color = NULL;
			temp->distance = NULL;
				temp->queue = NULL;

	free(*temp);
		*temp = NULL;
}
int getSize(Graph G){
	return G->size;
}
int getParent(Graph temp, int data){
	if( data > getOrder(temp) || data < 1)
	{
		printf("Error!\n");
			exit(1);
	}
	return temp->parent[data];
}
int getSource(Graph G){
	return G->source;
}
int getOrder(Graph G){
	return G->order;
}
int getDist(Graph temp, int data){
	if( data > getOrder(G) || data < 1 )
	{
		printf("Error!\n");
			exit(1);
	}
	return temp->distance[data];
}

void getPath(List list, Graph temp, int data){
	if( data > getOrder(temp) || data < 1 ){
		printf("Error!\n");
		exit(1);
	}

	
	if(getSource(temp) == NIL){
		printf("Error!\n");
		exit(1);
	}
	append(list, data);

	
	
	int tracker = data;
	while(temp->parent[tracker] != NIL){
		prepend(list, temp->parent[tracker]);
		tracker = temp->parent[tracker];
	}
	if(temp->source == tracker){
		return;
	}
	else{
		clear(list);
		prepend(list, NIL);
		return;
	}
}
void addEdge(Graph temp, int num1, int num2){
	int trcker1 = 0;
	int trcker2 = 0;
	int num3 = 0;

	if(temp == NULL){
			printf("Error1!\n");
		exit(1);
	}
	if(num1 < 1 || num1 > getOrder(temp)){
			printf("Error2!\n");
		exit(1);
	}
	if(num2 < 1 || num2 > getOrder(temp)){
			printf("Error3!\n");

		exit(1);
	}
	if(num1 == num2){
				return;
	}


	if(isEmpty(temp->adjArray[num2])){
		append(temp->adjArray[num2], num1);
			temp->size = temp->size + 1;

		trcker1 = 1;
	}
	if(isEmpty(temp->adjArray[num1])){
		append(temp->adjArray[num1], num2);
		temp->size = temp->size + 1;

		trcker2 = 1;
	}

	if(trcker1 == 0)
	{
	moveFront(temp->adjArray[num2]);
		for(num2=0;num2<length(temp->adjArray[num2]);num2++){
			if(num1 == get(temp->adjArray[num2])){
				trcker1 = 1;
				break;			
			}
			else if(num1 < get(temp->adjArray[num2])){
				insertBefore(temp->adjArray[num2], num1);
				temp->size = temp->size + 1;
						trcker1 = 1;
						break;			
			}
			else if( num2 == length(temp->adjArray[num2])-1 ){
				insertAfter(temp->adjArray[num2], num1);
				temp->size = temp->size + 1;
						trcker1 = 1;
						break;
			}
			else{
				moveNext(temp->adjArray[num2]);
			}
		}
	}
	if(trcker2 == 0){
		moveFront(temp->adjArray[num1]);
		for(num2=0;num2<length(temp->adjArray[num1]);num2++){
			if(num2 == get(temp->adjArray[num1])){
				trcker2 = 1;
				break;
			}
			else if(num2< get(temp->adjArray[num1])){
				insertBefore(temp->adjArray[num1], num2);
				temp->size = temp->size + 1;
					trcker2 = 1;
					break;
			}
			else if(num2 == length(temp->adjArray[num1])-1){
				insertAfter(temp->adjArray[num1], num2);
				temp->size = temp->size + 1;
					trcker2 = 1;
					break;
			}
			else{
				moveNext(temp->adjArray[num1]);
			}
		}
	}
}
void addArc(Graph temp, int num1, int num2)
{
	int num3 = 0;
	if(temp == NULL){
		printf("Error!\n");
			exit(1);
	}
	if(temp == num2)	{
		return;
	}
	if(num2 < 1 || num2 > getOrder(temp)){
		printf("Error!\n");
			exit(1);
	}
	if(temp < 1 || temp > getOrder(temp)){
		printf("Error!\n");
			exit(1);
	}
	if(isEmpty(temp->adjArray[temp])){
		append(temp->adjArray[temp], num2);
			temp->size = temp->size + 1;
				return;
	}
	
	moveFront(temp->adjArray[temp]);


	for(num3=0; num3<length(temp->adjArray[temp]) ;num3++){
		if(num2 == get(temp->adjArray[temp])){
			return;
		}
		else if(num2 < get(temp->adjArray[temp])){
			insertBefore(temp->adjArray[temp], num2);
				temp->size = temp->size + 1;
					return;
		}
		else if(num3 == length(temp->adjArray[temp])-1 ){
			insertAfter(temp->adjArray[temp], num2);
				temp->size = temp->size + 1;
					return;
		}
		else{
			moveNext(temp->adjArray[temp]);
		}
	}
}
void makeNull(Graph temp)
{
	for(int i = 1; i < temp->rIndex; i++){
		clear(temp->adjArray[i]);
	}
}
void BFS(Graph temp, int num1)
{
	
	if(temp == NULL){
		printf("Error!\n");
			exit(1);
	}
	if( num1 > getOrder(temp) || num1 < 1){
		printf("Error!\n");
			exit(1);
	}
	clear(temp->queue);
	
	for(int i = 1;i<temp->rIndex;i++){
		
		temp->parent[i] = NIL;
			temp->distance[i] = INF;
				temp->color[i] = WHITE; 
	}
		int num2;
		int num3;

		temp->source = num1;
		temp->color[num1] = GRAY;
		temp->parent[num1] = NIL;
		temp->distance[num1] = 0;		
		append(temp->queue, num1);	
	
	
	while(!isEmpty(temp->queue)){
		num2 = Deq(temp->queue);	
		moveFront(temp->adjArray[num2]);	
		
		for(int i = 0; i < length(temp->adjArray[num2]);i++) {
			num3 = get(temp->adjArray[num2]); 
			
			if(temp->color[num3] == WHITE)	{
				temp->color[num3] = GRAY;	
					temp->parent[num3] = num2;
						temp->distance[num3] = temp->distance[num2]+1;  
							append(temp->queue, num3); 
			}

			moveNext(temp->adjArray[num2]);	
		}

		temp->color[num2] = BLACK; 
	}
}
