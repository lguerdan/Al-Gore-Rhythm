#ifndef SECOND_FREQUENT_H
#define SECOND_FREQUENT_H

#include "input_error.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//Node of adjacentcy list
typedef struct adjListNode{
    unsigned int dest;
    struct adjListNode* next;
}AdjListNode;

//Wrapper for our adjacency list
typedef struct adjList{
    struct adjListNode *head;
}AdjList;

typedef struct graph{
   int V;
   struct adjList* array;
}Graph;

typedef struct stack{
   unsigned int * array;
   unsigned int top;
}Stack;

//Logistics
Graph * parseFileToGraph(char * filename);
unsigned int * checkLine(std::string string, unsigned int [2]);

//Graph handling
Graph * constructGraph(int);
void addEdge(Graph *, unsigned int, unsigned int);
AdjListNode* addListNode(unsigned int);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);

//Stack stuff (implemented via array)
Stack * createStack(unsigned int V);
void freeStack(Stack * stack);
void push(Stack * stack, unsigned int i);

//Cycle detection
bool isCyclicHelper(Graph * , int V, bool visited[], bool *call_stack);
bool isCyclic(Graph * graph);

//Topological sort
Stack * topologicalSort(Graph * graph);
void topologicalSortHelper(Graph *, unsigned int v, bool visited[], Stack * );

#endif