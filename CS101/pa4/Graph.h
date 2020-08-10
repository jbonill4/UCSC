//-----------------------------------------------------------------
////Jason Bonilla
////jbonill4
////Graph.h
////------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef GRAPH_INCLUDE_ 
#define GRAPH_INCLUDE_

typedef struct GraphObject* Graph;
typedef struct ListObj* List;

Graph newGraph(int n);
void freeGraph(Graph* pG);

int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);

void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);


#endif
