CISC360 PROJECT README
TEAM 10

Relevant files:
Main.cpp
RandGraph.cpp
Floyd-Wershall.cpp
Bellman-Ford.cpp
Dijkstra.cpp

To run time tests as is;
$ g++ -lrt -std=c++11 Main.cpp -o Main
$ ./Main

To run with valgrind (memory/cache data);
$ valgrind g++ -lrt -std=c++11 Main.cpp -o Main
$ valgrind ./Main