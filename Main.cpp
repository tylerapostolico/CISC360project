#include "Dijkstra.cpp"
//#include "RandGraph.cpp"
#include <iostream>
using namespace std;

typedef int** matrix_t;

matrix_t graph1,graph2,graph3,graph4,graph5;

// clock_gettime (CLOCK_MONOTONIC)

// link with realtime library -lrt

int main(){
    // You can change the seed
    srand(123);
    
    graph1 = adjacencyMatrixGenerator(10, 75, 10, true);
    graph2 = adjacencyMatrixGenerator(100, 20, 10, true);
    graph3 = adjacencyMatrixGenerator(1000, 2, 10, true);
    graph4 = adjacencyMatrixGenerator(10000, 1, 10, true);
    graph5 = adjacencyMatrixGenerator(10000, 1, 10, true);

    dijkstra(10, graph1, 0);
}