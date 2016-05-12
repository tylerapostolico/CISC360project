#include<stdio.h>
#include<stdlib.h>
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF2 99999

//  Returns an int**, can be treated just like a 2D array of size (n x n).
// "n" is the size of the adjacency Matrix (number of nodes)
// "percent" is a double for the odds that a given node x will be attached to different node y
// "largestWeight" is, like is sounds, the largest/heaviest weight allowed.
// "twoWay" is true if two way paths, false if one way paths

int** adjacencyMatrixGenerator(int n, double percent, int largestWeight, bool twoWay){
    
    //Not necessary
    if((twoWay!=true) && (twoWay!=false)){
        twoWay = true;
    }
    
    //Needed for % operations
    largestWeight--;
    
    //newPercent is calculated by making a proportionate percentage given a graph size    
    double p = (percent * .01) * n; 
    double newPercent = n + p;
    newPercent = newPercent - n*2;
    
    //Initializes the 2D array
    int** adjMatrix = new int*[n];
    for(int a = 0; a < n; a++){
        adjMatrix[a] = new int[n];
    }
    //Default value
    int m = -1;
    //If graph is undirected
    if(twoWay){
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
		//Generates a number that has the odds of being positive based on newPercent
                m = newPercent + rand()%n;
                //If negative, edge does not exist
                if(m<0){
                    adjMatrix[i][j] = INF2;
                    adjMatrix[j][i] = INF2;
                }
                //If positive, edge exists
                else{
                    m = m%largestWeight + 1;
                    adjMatrix[i][j] = m;
                    adjMatrix[j][i] = m;
                }
            }
        }
    }
    //For directed graphs
    else{
        for(int q = 0; q < n; q++){
            for(int w = 0; w < n; w++){
                m = newPercent + rand()%n;
                if(m<0){
                    adjMatrix[q][w] = INF2;
                }
                else{
                    m = m%largestWeight + 1;
                    adjMatrix[q][w] = m;
                }
            }
        }
    }
    //Sets all nodes to have no edges to themselves
    for(int b = 0; b < n; b++){
        adjMatrix[b][b] = 0;
    }
    return adjMatrix;
}