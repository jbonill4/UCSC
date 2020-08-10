//-----------------------------------------------------------------
////Jason Bonilla
////jbonill4
////Graph.h
////PA5
////------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef GRAPH_INCLUDE
#define GRAPH_INCLUDE

typedef struct GraphObject* Graph;
typedef struct ListObj* List;

Graph newGraph(int n);
void freeGraph(Graph* pG);
Graph getGraph(Graph curGraph);

int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u);
int getDiscover(Graph G, int u);
int getFinish(Graph G, int u);
void addArc(Graph G, int u, int v);

void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
 



#endif
