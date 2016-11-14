#include "../lib/detect_cycle.h"
using namespace std;

//Usage: after running make, run with ./Lmg4n8HW3
int main(int argc,char ** argv){
  if(argc != 3){
    exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
  }

  //First we parse the file into a graph. File opperations & graph representation handled here
   Graph * graph = parseFileToGraph(argv[1]);

   // Check for a cycle in the graph using DFS. If true print 0 to input file.
   if(isCyclic(graph)){

      ofstream outfile;
      outfile.open(argv[2]);
      outfile << 0 << endl;
      outfile.close();

   }else{
      // If no cycle is present, print a topological sort of the graph using a modified DFS. Store topological sort in a stack.
      ofstream outfile;
      outfile.open(argv[2]);
      Stack * topo_sort = topologicalSort(graph);

      // Pop stack until empty and print to file.
      while (topo_sort->top >= 1){
        outfile << topo_sort->array[topo_sort->top] << endl;
        topo_sort->top--;
      }

      // Close files and free resources.
      outfile.close();
      free(topo_sort);
   }

   freeGraph(graph);
   return 0;
}

// Main function to calculate topological sort. Uses dfs and pushes black edges to stack
// storing topological sort in stack.
Stack * topologicalSort(Graph * graph){

   Stack * topo_stack = createStack(graph->V);
   bool * visited = new bool[graph->V];

   for(int i = 0; i < graph->V + 1; i++)
      visited[i] = false;

   for(int i = 1; i < graph->V + 1; i++){
      if(visited[i] == false){
         topologicalSortHelper(graph, i, visited, topo_stack);
      }
   }
   delete visited;
   return topo_stack;
}

//Utility function to recurse down and track visited nodes. Pushes visited to stack.
void topologicalSortHelper(Graph * graph, unsigned int v, bool visited[], Stack * stack){
   visited[v] = true;

   AdjListNode * runner = graph->array[v].head;

   while(runner != NULL){
      if(!visited[runner->dest]){
         topologicalSortHelper(graph, runner->dest, visited, stack);
      }
      runner = runner->next;
   }
   push(stack, v);
}

// Helper function to call DFS on subtrees. Tracks grey/black nodes through visited and call stack arrays.
bool isCyclicHelper(Graph * graph, int v, bool visited[], bool *call_stack){

   if(visited[v] == false){

      visited[v] = true;
      call_stack[v]= true;
      AdjListNode * runner = graph->array[v].head;

      while(runner != NULL){
         if(!visited[runner->dest] && isCyclicHelper(graph, runner->dest, visited, call_stack)){
            return true;
         }
         else if(call_stack[runner->dest]){
            return true;
         }
         runner = runner->next;
         }
   }
   call_stack[v] = false;
   return false;
}

// Detects cycle in graph by calling modified DFS to track visited nodes.
bool isCyclic(Graph * graph){
   bool*  visited = new bool[graph->V + 1];
   bool * call_stack = new bool[graph->V + 1];

   for(unsigned int i = 0; i <= graph->V; i++){
        visited[i] = false;
        call_stack[i] = false;
    }

    for(unsigned int i = 1; i <= graph->V; i++)
        if (isCyclicHelper(graph, i, visited, call_stack))
            return true;

   return false;
}

// Handle file opperation, parsing, and transfer to adjacency list
Graph * parseFileToGraph(char * filename){
   // open file from args and verify intact.
   ifstream infile;
   string buffer;
   infile.open(filename);
   if (!infile.is_open()){
      exit(FILE_FAILED_TO_OPEN);
   }

   getline(infile, buffer);
   if (buffer.empty())
      exit(PARSING_ERROR_EMPTY_FILE);

   int i = 0;
   while(buffer[i] != '\0'){
      if(!isdigit(buffer[i]))
         exit(PARSING_ERROR_INVALID_FORMAT);
      i++;
   }

   unsigned int num_verts = stoi(buffer);
   Graph * graph = constructGraph(num_verts);
   unsigned int edge[2];
   edge[0] = 0;
   edge[1] = 0;

   // //Initialize intiger array of size of file. Scan for num lines first.
   // unsigned int line_count = 0;
   while(getline(infile, buffer)){

      //Parse each line of input for format. Note: no instructions given for empty lines but treated as errors
      checkLine(buffer, edge);
      if(edge[0] == -1 || buffer.empty()){
         exit(PARSING_ERROR_INVALID_FORMAT);
      }
      if (edge[0] > num_verts ||  edge[1] > num_verts)
         exit(INTEGER_IS_NOT_A_VERTEX);

      addEdge(graph, edge[0], edge[1]);
   }

   // //Close input file and verify success.
   infile.close();
   if (infile.is_open()){
      exit(FILE_FAILED_TO_CLOSE);
   }
   return graph;
}

// Initialize graph of size V
Graph * constructGraph(int V){
   Graph * graph = (Graph *) malloc(sizeof(Graph));
   graph->V = V;
   graph->array = (adjList *) malloc(sizeof(adjList) * V + 1);

   int i = 0;
   for(int i = 0; i < V; i++){
      graph->array[i].head = NULL;
   }
   return graph;
}

//Add edge to a given graph
void addEdge(Graph * graph, unsigned int src, unsigned int dest){
   AdjListNode * newNode = addListNode(dest);
   newNode->next = graph->array[src].head;
   graph->array[src].head = newNode;
}

// Adds new node to adjacency list
AdjListNode* addListNode(unsigned int dest){
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

//Ensure each line of input matches character constraints (is only non-neg int)
//and return integers corresponding to edges
unsigned int * checkLine(string str, unsigned int edge[2]){
   char buffer[256];
   if(str[0] !='('){
      edge[0] = -1;
      return edge;
   }

   int i = 1;
   int tmp = 0;

   if(str[1] == '-')
      exit(INTEGER_IS_NOT_A_VERTEX);

   while(str[i] != ',' && str[i] != '\0'){
      if (!isdigit(str[i])){
         edge[0] = -1;
         return edge;
      }
      buffer[tmp] = str[i];
      tmp++;
      i++;
   }
   if(tmp == 0){
      edge[0] = -1;
      return edge;
   }
   buffer[tmp] = '\0';
   edge[0] = stoi(buffer);

   // Parse up to comma
   if(str[i] != ','){
      edge[0] = -1;
      return edge;
   }
   i++;
   tmp = 0;

   if(str[i] == '-')
      exit(INTEGER_IS_NOT_A_VERTEX);

   while(str[i] != ')' && str[i] != '\0'){
      if (!isdigit(str[i])){
         edge[0] = -1;
         return edge;
      }
      buffer[tmp] = str[i];
      tmp++;
      i++;
   }
   if(tmp == 0){
      edge[0] = -1;
      return edge;
   }
   buffer[tmp] = '\0';
   edge[1] = stoi(buffer);

   if(str[i] != ')'){
      edge[0] = -1;
      return edge;
   }
   return edge;
}

// Utility function to print graph representation
void printGraph(Graph* graph){
    int v;
    for (v = 1; v <= graph->V; ++v){
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Utility function to free graph resources
void freeGraph(Graph* graph){
    int v;
    for (v = 0; v <= graph->V; ++v){
        AdjListNode* pCrawl = graph->array[v].head;
        AdjListNode* pStore = pCrawl;
        while (pCrawl){
            pCrawl = pCrawl->next;
            free(pStore);
            pStore = pCrawl;
        }
    }
    free(graph->array);
    free(graph);
}

// Push to next open index in stack
void push(Stack * stack, unsigned int i){
   stack->top++;
   stack->array[stack->top] = i;
}

//Allocate new stack of size V
Stack * createStack(unsigned int V){
   Stack *  stack = (Stack*) malloc(sizeof(Stack));
   stack->top = 0;
   stack->array = (unsigned int * )malloc(sizeof(unsigned int) * V + 1);
   return stack;
}

//Free stack resources
void freeStack(Stack * stack){
   free(stack->array);
   free(stack);
   return;
}
