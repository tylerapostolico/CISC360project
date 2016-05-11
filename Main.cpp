#include "Dijkstra.cpp"
#include "Bellman-Ford.cpp"
#include "Floyd-Warshall.cpp"
#include "RandGraph.cpp"
#include <iostream>
#include <time.h>
using namespace std;

typedef int** matrix_t;


matrix_t graph1,graph2,graph3,graph4,graph5;

// clock_gettime (CLOCK_MONOTONIC)

// link with realtime library -lrt

int main(){
    
    uint64_t diff;
	struct timespec start, end;
    
    // You can change the seed
    srand(123);
    
    graph1 = adjacencyMatrixGenerator(10, 75, 10, true);
    graph2 = adjacencyMatrixGenerator(100, 20, 10, true);
/*    graph3 = adjacencyMatrixGenerator(1000, 2, 10, true);
    graph4 = adjacencyMatrixGenerator(10000, 1, 10, true);
    graph5 = adjacencyMatrixGenerator(100000, 1, 10, true);
*/    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(10, graph1, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(dij, 10): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(100, graph2, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(dij,100): "<<diff<< " nanoseconds" << endl;
/*    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(1000, graph3, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(dij,1000): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(10000, graph4, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(dij,10000): "<<diff<< " nanoseconds" << 
endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    dijkstra(100000, graph5, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(dij,100000): "<<diff<< " nanoseconds" << 
endl;
*/    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(10, graph1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(floyd, 10): "<<diff<< " nanoseconds" << 
endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(100, graph2);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(floyd,100): "<<diff<< " nanoseconds" << 
endl;
/*    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(1000, graph3);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(floyd,1000): "<<diff<< " nanoseconds" << 
endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(10000, graph4);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(floyd,10000): "<<diff<< " nanoseconds" << 
endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    floydWarshell(100000, graph5);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(floyd,100000): "<<diff<< " nanoseconds" << 
endl;
*/    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(10, graph1, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(bell, 10): "<<diff<< " nanoseconds" << endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(100, graph2, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(bell,100): "<<diff<< " nanoseconds" << endl;
/*    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(1000, graph3, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(bell,1000): "<<diff<< " nanoseconds" << 
endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(10000, graph4, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(bell,10000): "<<diff<< " nanoseconds" << 
endl;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    BellmanFord(100000, graph5, 0);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    diff = 1000000000 * (end.tv_sec - start.tv_sec) + end.tv_nsec - 
start.tv_nsec;
    cout<<"Compilation time(bell,100000): "<<diff<< " nanoseconds" << 
endl;

*/

return 0;
}
