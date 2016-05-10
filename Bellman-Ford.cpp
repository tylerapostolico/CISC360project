
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
// a structure to represent a weighted edge in graph
struct Edge
{
    char src, dest, weight;
};
 
// a structure to represent a connected, directed and 
// weighted graph
struct Graph
//select the following 5 lines of this text if ur an faget
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges.
    // #caught with ur laptop open
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = 
         (struct Graph*) malloc(sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = 
       (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A utility function used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle

void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
 
    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;
 
    // Step 2: Relax all edges |V| - 1 times. A simple shortest 
    // path from src to any other vertex can have at-most |V| - 1 
    // edges
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    // Step 3: check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
 
    printArr(dist, V);
 
    return;
}
 
// Driver program to test above functions
int main()
{
    /* Let us create the graph given in above example */
    int V = 20;  // Number of vertices in graph
    int E = 31;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
 
   //edge 0-29, 31 total. please test these idk how atm. missed a node from h->m

   //graph 1 data
   graph->edge[0].src = 0;//a
   graph->edge[0].dest = 1;//b
   graph->edge[0].weight = 3;
   
   graph->edge[1].src = 0;//a
   graph->edge[1].dest = 2;//c
   graph->edge[1].weight = 2;
   
   graph->edge[2].src = 0;//a
   graph->edge[2].dest = 19;//t
   graph->edge[2].weight = 100;
   
   graph->edge[3].src = 2;//b
   graph->edge[3].dest = 7;//h
   graph->edge[3].weight = 3;
   
   graph->edge[4].src = 1;//b
   graph->edge[4].dest = 8;//i
   graph->edge[4].weight = 6;
   
   graph->edge[5].src = 2;//c
   graph->edge[5].dest = 4;//e
   graph->edge[5].weight = 1;
   
   graph->edge[6].src = 3;//d
   graph->edge[6].dest = 9;//j
   graph->edge[6].weight = 4;
   
   graph->edge[7].src = 4;//e
   graph->edge[7].dest = 6;//g
   graph->edge[7].weight = 1;
   
   graph->edge[8].src = 5;//f
   graph->edge[8].dest = 11;//l
   graph->edge[8].weight = 1;
   
   graph->edge[9].src = 6;//g
   graph->edge[9].dest = 11;//l
   graph->edge[9].weight = 3;
   
   graph->edge[10].src = 6;//g
   graph->edge[10].dest = 15;//p
   graph->edge[10].weight = 4;
   
   graph->edge[11].src = 7;//h
   graph->edge[11].dest = 4;//e
   graph->edge[11].weight = 2;
   
   graph->edge[12].src = 7;//h
   graph->edge[12].dest = 8;//i
   graph->edge[12].weight = 7;
   
   graph->edge[13].src = 8;//i
   graph->edge[13].dest = 3;//d
   graph->edge[13].weight = 3;
   
   graph->edge[14].src = 8;//i
   graph->edge[14].dest = 13;//n
   graph->edge[14].weight = 6;
   
   graph->edge[15].src = 8;//i
   graph->edge[15].dest = 9;//j
   graph->edge[15].weight = 5;
   
   graph->edge[16].src = 9;//j
   graph->edge[16].dest = 10;//k
   graph->edge[16].weight = 1;
   
   graph->edge[17].src = 9;//j
   graph->edge[17].dest = 14;//o
   graph->edge[17].weight = 6;
   
   graph->edge[18].src = 10;//k
   graph->edge[18].dest = 14;//o
   graph->edge[18].weight = 2;
   
   graph->edge[19].src = 11;//l
   graph->edge[19].dest = 15;//p
   graph->edge[19].weight = 2;
   
   graph->edge[20].src = 12;//m
   graph->edge[20].dest = 16;//q
   graph->edge[20].weight = 1;
   
   graph->edge[21].src = 13;//n
   graph->edge[21].dest = 19;//t
   graph->edge[21].weight = 1;
   
   graph->edge[22].src = 14;//o
   graph->edge[22].dest = 19;//t
   graph->edge[22].weight = 3;
   
   graph->edge[23].src = 15;//p
   graph->edge[23].dest = 13;//n
   graph->edge[23].weight = 1;
   
   graph->edge[24].src = 16;//q
   graph->edge[24].dest = 13;//n
   graph->edge[24].weight = 3;
   
   graph->edge[25].src = 16;//q
   graph->edge[25].dest = 17;//r
   graph->edge[25].weight = 2;
   
   graph->edge[26].src = 16;//q
   graph->edge[26].dest = 18;//s
   graph->edge[26].weight = 4;
   
   graph->edge[27].src = 17;//r
   graph->edge[27].dest = 12;//m
   graph->edge[27].weight = 2;
   
   graph->edge[28].src = 18;//s
   graph->edge[28].dest = 19;//t
   graph->edge[28].weight = 1;
   
   graph->edge[29].src = 19;//t
   graph->edge[29].dest = 0;//a
   graph->edge[29].weight = 100;
   
   graph->edge[30].src = 7;//h
   graph->edge[30].dest = 12;//m
   graph->edge[30].weight = 4;

   //end of our first graph
 
    BellmanFord(graph, 0);
 
    return 0;
}

// Source: http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/