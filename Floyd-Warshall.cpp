// C Program for Floyd Warshall Algorithm
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
 
// Number of vertices in the graph
//#define V 20
 
/* Define Infinite as a large enough value. This value will be used
  for vertices not connected to each other */
#define INF 99999
 
 using namespace std;
 
// A function to print the solution matrix
//void printSolution(int V, int dist[][]);
 
// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshell (int V, int** graph)
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    
    //int** dist = new int*[V];
    int** dist = graph;
    int i, j, k;
 
    /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
/*    
    cout<<("Following matrix shows the shortest distances between every pair of vertices ")<<endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<("INF ");
            else
                cout<<(dist[i][j]) << (" ");
        }
        cout<<endl;
    }
    
    cout <<("This shows the shortest distance of every point from the source") << endl;
    for (int i = 0; i<V; i++) {
        cout <<(i) << ("    ") << dist[0][i] << endl;
    }
*/ 
    // Print the shortest distance matrix
    //printSolution(V, dist);
}
 
/* A utility function to print solution */
void printSolution(int V, int** dist)
{
    cout<<("Following matrix shows the shortest distances between every pair of vertices ")<<endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<("INF ");
            else
                cout<<(dist[i][j]) <<(" ");
        }
        cout<<endl;
    }
}
 
