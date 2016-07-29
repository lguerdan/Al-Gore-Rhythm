// #include <stdio.h>
// #include <stdlib.h>

// typedef struct edge {
//   int vertex;
//   struct edge * next;
// }Edge;

// Edge * insertEdge(Edge * currentHead, int vert);

// int main(void){

//   int numedges, numverticies, v1, v2;
//   printf("Enter the number of verticies:\n");
//   scanf("%d", &numverticies);

//   printf("Enter the number of edges\n");
//   scanf("%d", &numedges);

//   Edge * adjList[numverticies + 1];
//   for(int i = 1; i <= numverticies; i++){
//     adjList[i] = NULL;
//   }

//   for(int i = 1; i <= numedges; i++){
//     scanf("%d%d", &v1, &v2);

//     adjList[v1] = insertEdge(adjList[v1], v2);
//     adjList[v2] = insertEdge(adjList[v2], v1);
//   }
//   for (int i = 1; i < numverticies; i++){
//     printf("Nodes adjacent to %d.", adjList[i]->vertex);
//     Edge * traverse = adjList[i];

//     while (traverse != NULL){
//       printf("%d-> ",traverse->vertex);
//       traverse = traverse->next;
//     }
//   }

// }

// Edge * insertEdge(Edge * currentHead, int vert){
//   Edge * new = (Edge *)malloc(sizeof(Edge));

//   new->vertex = vert;
//   new->next = currentHead;
//   return new;
// }
