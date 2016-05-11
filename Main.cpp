#include "Dijkstra.cpp"
#include "Bellman-Ford.cpp"
#include "Floyd-Warshall.cpp"
#include "RandGraph.cpp"
#include <iostream>
#include <time.h>
using namespace std;

typedef int** matrix_t;


matrix_t graph1,graph2,graph3,graph4,graph5,graph6,graph7,graph8,graph9,graph10;

// clock_gettime (CLOCK_MONOTONIC)

// link with realtime library -lrt

int main(){
    
    uint64_t diff;
	struct timespec start, end;
    
    // You can change the seed
    srand(123);
    
    graph1 = adjacencyMatrixGenerator(10, 90, 100, true);
    graph2 = adjacencyMatrixGenerator(100, 90, 100, true);
    graph3 = adjacencyMatrixGenerator(1000, 90, 100, true);
    graph4 = adjacencyMatrixGenerator(2000, 90, 100, true);
    graph5 = adjacencyMatrixGenerator(3000, 90, 100, true);

    graph6 = adjacencyMatrixGenerator(10, 10, 100, true);
    graph7 = adjacencyMatrixGenerator(100, 10, 100, true);
    graph8 = adjacencyMatrixGenerator(1000, 10, 100, true);
    graph9 = adjacencyMatrixGenerator(2000, 10, 100, true);
    graph10 = adjacencyMatrixGenerator(3000, 10, 100, true);

    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(10, graph1, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 10, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(100, graph2, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 100, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(1000, graph3, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 1000, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(2000, graph4, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 2000, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(3000, graph5, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 3000, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(10, graph1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 10, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(100, graph2);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 100, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(1000, graph3);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 1000, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(2000, graph4);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 2000, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(3000, graph5);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 3000, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(10, graph1, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 10, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(100, graph2, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell,100, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(1000, graph3, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 1000, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(2000, graph4, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 2000, dense): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(3000, graph5, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 3000, dense): "<<diff<< " nanoseconds" << endl;
    
    
    
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(10, graph6, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 10, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(100, graph7, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij,100, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(1000, graph8, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 1000, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(2000, graph9, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 2000, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(3000, graph10, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(dij, 3000, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(10, graph6);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 10, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(100, graph7);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 100, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(1000, graph8);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 1000, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(2000, graph9);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 2000, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(3000, graph10);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(floyd, 3000, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(10, graph6, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 10, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(100, graph7, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 100, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(1000, graph8, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 1000, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(2000, graph9, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 2000, sparse): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(3000, graph10, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    cout<<"Compilation time(bell, 3000, sparse): "<<diff<< " nanoseconds" << endl;
return 0;
}
