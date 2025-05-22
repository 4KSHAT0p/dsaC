#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// assuming that the user is not dumb(i.e. he/she is not entering redundant values)
// undirected graph
// zero based indexing nodes

typedef struct PAIR
{
    int first;
    int second;
} pair;

typedef struct Chains
{
    int Data;
    int chainCount;
} CH;

typedef struct GRAPH
{
    CH **adjList;
    int countVertex;
} G;

void ADDVERTEX(G *, int);
void ADDEDGE(G *, int, int);
void DISPLAY(G);
void BFS(G);
void DFS(G);
void dfsUtil(G, int, bool *);
int Nprovinces(G);
//void DESTROYGRAPH(G**);
bool hasCYCLE(G);
bool detect(G, int, bool *);

bool dfsCycle(int, int, G, bool *);
bool hasCYCLEdfs(G);

void topSORT(G);
void dfsTOPSORT(G, bool *, int *, int *, int);
int main()
{

    // int **ADJLIST=NULL;
    // int *arr=NULL;

    // ADDVERTEX(&ADJLIST,65);
    // ADDVERTEX(&ADJLIST,54);
    // printf("%p",ADJLIST);
    // printf("%d",*(ADJLIST[0]+1)); //gives 0 because we try to access unallocated single pointer
    // printf("%d",ADJLIST[1]); //gives segfault because we try to access unallocated double pointer
    /*int rows=0;

    int **p=calloc(2,sizeof(int*));

    *p=calloc(1,sizeof(int));
    **p=5;

    *p=realloc(*p,2*sizeof(int));
    *(*p+1)=66;
    printf("%d",);*/

    G *g1 = calloc(1, sizeof(G));

    ADDVERTEX(g1, 0);
    ADDVERTEX(g1, 1);
    ADDVERTEX(g1, 2);
    ADDVERTEX(g1, 3);

    ADDEDGE(g1, 0, 1);
    ADDEDGE(g1, 1, 2);
    ADDEDGE(g1, 0, 3);
    // ADDEDGE(g1, 2, 0);
    // ADDEDGE(g1, 2, 3);
    //  ADDEDGE(g1, 0, 3);

    DISPLAY(*g1);
    printf("\n\n");

    topSORT(*g1);

  //  DESTROYGRAPH(&g1);
    /*if (hasCYCLE(*g1))
    {
        printf("This graph has a cycle");
    }
    else
    {
        printf("No cycle");
    }*/

    // BFS(*g1);
    //  DFS(*g1);

    // printf("\n\n%d", Nprovinces(*g1));

    // printf("%d",(*(*(g1->adjList+2))).chainCount); //accessing chain count
    // printf("%d", (**(g1->adjList + 7)).Data);  //accessing nodes
    // printf("%d", (*(*(g1->adjList+1)+1)).Data);  //accessing list members
    return 0;
}

void ADDVERTEX(G *graph, int vertex)
{
    if (graph->adjList == NULL)
    {
        graph->adjList = calloc(1, sizeof(CH *)); // allocate memory for single pointers to integers
        graph->countVertex = 0;
        *(graph->adjList) = calloc(1, sizeof(CH)); // allocate memory for integers
        (**(graph->adjList)).Data = vertex;
        (**(graph->adjList + graph->countVertex)).chainCount = 1;
        graph->countVertex++;
    }
    else
    {
        graph->adjList = realloc(graph->adjList, (graph->countVertex + 1) * sizeof(CH *));
        *(graph->adjList + graph->countVertex) = calloc(1, sizeof(CH));
        (**(graph->adjList + graph->countVertex)).Data = vertex;
        (**(graph->adjList + graph->countVertex)).chainCount = 1;
        graph->countVertex++;
    }
    // count stored in first element of the array
}

void ADDEDGE(G *graph, int a, int b)
{
    *(graph->adjList + a) = realloc(*(graph->adjList + a), ((*(graph->adjList + a))->chainCount + 1) * sizeof(CH));
    *(graph->adjList + b) = realloc(*(graph->adjList + b), ((*(graph->adjList + b))->chainCount + 1) * sizeof(CH));

    (*(*(graph->adjList + a) + (*(graph->adjList + a))->chainCount)).Data = b;
    // (*(*(graph->adjList + b) + (*(graph->adjList + b))->chainCount)).Data = a;

    (*(graph->adjList + a))->chainCount++;
    // (*(graph->adjList + b))->chainCount++;
}

void DISPLAY(G graph)
{
    for (int i = 0; i < graph.countVertex; i++)
    {
        printf("%d ", (**(graph.adjList + i)).Data);
        for (int j = 1; j < (**(graph.adjList + i)).chainCount; j++)
        {
            printf("->%d", (*(*(graph.adjList + i) + j)).Data);
        }
        printf("\n");
    }
}

void BFS(G graph)
{
    int starting_node;
    printf("Enter the starting node for BFS traversal\n");
    scanf("%d", &starting_node);

    bool visited[graph.countVertex];

    for (int i = 0; i < graph.countVertex; i++)
    {
        if (i == starting_node)
        {
            visited[i] = true;
        }
        else
        {
            visited[i] = false;
        }
    }
    int queue[graph.countVertex];
    int front = -1;
    int rear = -1;

    queue[++front] = starting_node;

    rear++;

    while (front <= rear)
    {
        printf("%d ", queue[front]);
        for (int i = 1; i < (*(graph.adjList + queue[front]))->chainCount; i++)
        {
            if (!visited[(*(graph.adjList + queue[front]) + i)->Data])
            {
                queue[++rear] = (*(graph.adjList + queue[front]) + i)->Data; // enqueue
                visited[(*(graph.adjList + queue[front]) + i)->Data] = true;
            }
        }
        front++; // dequeue
    }
}

void DFS(G graph)
{
    int starting_node;
    printf("Enter the starting node for DFS traversal\n");
    scanf("%d", &starting_node);

    bool visited[graph.countVertex];

    for (int i = 0; i < graph.countVertex; i++)
    {
        visited[i] = false;
    }

    dfsUtil(graph, starting_node, visited);
}

void dfsUtil(G gg, int start, bool *vis)
{
    *(vis + start) = true;
    printf("%d\n", start);

    for (int i = 1; i < (*(gg.adjList + start))->chainCount; i++)
    {
        if (!vis[(*(gg.adjList + start) + i)->Data])
        {
            dfsUtil(gg, (*(gg.adjList + start) + i)->Data, vis);
        }
    }
}

int Nprovinces(G gr)
{
    bool visited[gr.countVertex];
    int count = 0;
    for (int i = 0; i < gr.countVertex; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < gr.countVertex; i++)
    {
        if (!visited[i])
        {
            dfsUtil(gr, i, visited); // visited array already passed by reference
            count++;
        }
    }
    return count;
}

bool detect(G graph, int src, bool *visi)
{
    visi[src] = true;
    pair queue[graph.countVertex];
    int front = -1;
    int rear = -1;

    queue[++front].first = src;
    queue[front].second = -1;
    rear++;

    while (front <= rear)
    {
        int node = queue[front].first;    // node
        int parent = queue[front].second; // parent

        front++; // popping

        for (int i = 1; i < (*(graph.adjList + node))->chainCount; i++)
        {
            if (!visi[(*(graph.adjList + node) + i)->Data])
            {
                visi[(*(graph.adjList + node) + i)->Data] = true;
                queue[++rear].first = (*(graph.adjList + node) + i)->Data;
                queue[rear].second = (*(graph.adjList + node))->Data;
            }
            else if ((*(graph.adjList + node) + i)->Data != parent) // if a vertex is visited adjacent to a vertex (A) and it's not a parent as parent is also a neighbour of A
            {
                return true;
            }
        }
    }
    return false;
}

bool hasCYCLE(G graph) // TC = O(V+2E)  SC= O(N)
{
    bool visited[graph.countVertex];
    for (int i = 0; i < graph.countVertex; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < graph.countVertex; i++)
    {
        if (!visited[i])
        {
            if (detect(graph, i, visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool dfsCycle(int node, int parent, G graph, bool *visi)
{
    visi[node] = true;
    for (int i = 1; i < (*(graph.adjList + node))->chainCount; i++)
    {
        if (!visi[(*(graph.adjList + node) + i)->Data])
        {
            if (dfsCycle((*(graph.adjList + node) + i)->Data, node, graph, visi))
            {
                return true;
            }
        }
        else if ((*(graph.adjList + node) + i)->Data != parent)
        {
            return true;
        }
    }
    return false;
}

bool hasCYCLEdfs(G graph)
{
    bool visited[graph.countVertex];

    for (int i = 0; i < graph.countVertex; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < graph.countVertex; i++)
    {
        if (!visited[i])
        {
            if (dfsCycle(i, -1, graph, visited))
            {
                return true;
            }
        }
    }
    return false;
}

void dfsTOPSORT(G graph, bool *vis, int *st, int *top, int node)
{
    vis[node] = true;
    for (int i = 1; i < (*(graph.adjList + node))->chainCount; i++)
    {
        if (!vis[(*(graph.adjList + node) + i)->Data])
        {
            dfsTOPSORT(graph, vis, st, top, (*(graph.adjList + node) + i)->Data);
        }
    }
    st[++(*top)] = node;
}

void topSORT(G graph)
{
    int stack[graph.countVertex];
    int top = -1;

    bool vis[graph.countVertex];
    for (int i = 0; i < graph.countVertex; i++)
    {
        vis[i] = false;
    }

    for (int i = 0; i < graph.countVertex; i++)
    {
        if (!vis[i])
        {
            dfsTOPSORT(graph, vis, stack, &top, i);
        }
    }

    printf("top is %d\n", top);
    while (top != -1)
    {
        printf("%d ", stack[top]);
        top--;
    }
}


/*void DESTROYGRAPH(G** graph)
{
    for(int i=(*graph)->countVertex-1;i>=0;i--)
    {
        for(int j=(*((*graph)->adjList+i))->chainCount-1;j>=0;j--)
        {
            free(*((*graph)->adjList+i)+j);
            printf("\nGraph Destroyed inner Successfully\n");
        }
        free((*graph)->adjList+i);
        printf("\nGraph Destroyed outer Successfully\n");
    }
   
}*/
