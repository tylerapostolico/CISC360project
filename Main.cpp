#include "RandGraph.cpp"
#include "GlobalGraphs.cpp"
#include <iostream>
#include <random>
using namespace std;

int** graph1;
int** graph2;
int** graph3;
int** graph4;
int** graph5;

int main(){
    graph1 = adjacencyMatrixGenerator(10, 75, 10, true);
    graph2 = adjacencyMatrixGenerator(100, 20, 10, true);
    graph3 = adjacencyMatrixGenerator(1000, 2, 10, true);
    graph4 = adjacencyMatrixGenerator(10000, 1, 10, true);
    graph5 = adjacencyMatrixGenerator(10000, 1, 10, true);
}