#include<stdio.h>
#include<stdlib.h>
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF2 99999

//Returns an int**, can be treated just like a 2D array of size (n x n).
// "n" is the size of the adjacency Matrix (number of nodes)
// "percent" is the percentage of nodes that a the avergae node has a path to
// "largestWeight" is, like is sounds, the largest/heaviest weight allowed.
// "twoWay" is true if two way paths, false if one way paths
int** adjacencyMatrixGenerator(int n, int percent, int largestWeight, bool twoWay){
    
    //Not necessary
    if((twoWay!=true) && (twoWay!=false)){
        twoWay = true;
    }
    
    largestWeight--;
    
    srand(time(NULL));
    int newPercent;
    if(percent>=0 && percent<=100){
        newPercent = 100 - percent;
    }
    //default case
    else{
        newPercent = 80;
    }
    
    int** adjMatrix = new int*[n];
    for(int a = 0; a < n; a++){
        adjMatrix[a] = new int[n];
    }
    int m = -1;
    if(twoWay){
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                m = (rand()%100) - newPercent;
                if(m<0){
                    adjMatrix[i][j] = INF2;
                    adjMatrix[j][i] = INF2;
                }
                else{
                    m = m%largestWeight + 1;
                    adjMatrix[i][j] = m;
                    adjMatrix[j][i] = m;
                }
            }
        }
    }
    else{
        for(int q = 0; q < n; q++){
            for(int w = 0; w < n; w++){
                m = (rand()%100) - (newPercent -1);
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
    for(int b = 0; b < n; b++){
        adjMatrix[b][b] = 0;
    }
    return adjMatrix;
}

/*
int main(){
    int n = 10;
    int percent = 46;
    bool diagonal = true;
    int largestWeightIn = 12;
    int** meme = adjacencyMatrixGenerator(n, percent, largestWeightIn, diagonal);
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<meme[i][j]<<"   ";
        }
        cout<<endl;
    }
}*/