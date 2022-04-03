// created by Nicholas Garrett
// zagruzhet

#ifndef PRIMSALGORITHM_H
#define PRIMSALGORITHM_H

#include <iostream>
#include <fstream>
#include <string>
#include <String.h>
#include <stdio.h>
#include <stdlib.h>

#include "logging.h"

#define N 10

using namespace std;


class PrimsAlgorithm
{
	private:
		
		// starting point is chosen at random
	   	int currentNode;
	   	
	   	// variable containing the next node to check
		int nextNode;		   
	   	
	   	// build minimum spanning tree
	   	int minSpanningTree[N][N] = {0};
	   	
	   	//create array of vertices to store if they have been visited or not
	   	bool visitedNodes[N] = {false};
	   	
	   	// nodes connectable to from the current node
	   	int connectableNodes[N][3] = {0};
	   	
	   	// boolean to determine if all nodes have been visited or not
	   	int nodesVisited;


	public:
		PrimsAlgorithm();
		~PrimsAlgorithm();
		
		
		// printMatrix
		// print an inputted matrix
		/*
			input: matrix (int [10][10]), matrix to print
		*/
		void printMatrix( int matrix[N][N])
		{
			// print the matrix
			cout << "matrix:\n";
		   	for(int i = 0; i < N; i++)
		   	{
		   		for( int j = 0; j < N; j++)
		   		{
		   			cout << matrix[i][j] << " ";	
				}
				cout << "\n";
		   	}
		   	cout << "\n";
		}
		
		
		
		// distanceOneNode
		// find all nodes that are a single step away
		/*
			input: matrix (int [N][N]) matrix of nodes 
		*/
		int distanceOneNodes( int matrix[N][N] )
		{
			
			// conNodeToWrite variable to store iterated value to write to in connectableNodes array
			int conNodeToWrite = 0;
			
			// zero out the connectableNodes array
			for(int i = 0; i < 10; i++)
			{
				connectableNodes[i][0] = -1;
				cout << "clearing: connectableNodes[" << i << "]:" << connectableNodes[i][0] << " \n";

			}

			
			// go through the rows corresponding to currentNode, and add any non-zero values to the connectable nodes matrix
			for( int i = 0; i < N; i++ )
			{
				if( matrix[i][currentNode] != 0 )
					connectableNodes[conNodeToWrite][0] = matrix[i][currentNode];
					connectableNodes[conNodeToWrite][1] = currentNode;
					connectableNodes[conNodeToWrite++][2] = i;
					cout << "matrix["<<i<<"]["<<currentNode<<"] : "<<matrix[i][currentNode] << "\n";
					//cout << "row. connectableNodes[" << conNodeToWrite << "]:" << connectableNodes[conNodeToWrite] << " \n";
			}
			
			
			
			conNodeToWrite = 0;
			// go through the columns corresponding to currentNode, and add any non-zero values to the connectable nodes matrix
			for( int i = 0; i < N; i++ )
			{
				if( matrix[currentNode][i] != 0 )
					connectableNodes[conNodeToWrite][0] = matrix[currentNode][i];
					connectableNodes[conNodeToWrite][1] = currentNode;
					connectableNodes[conNodeToWrite++][2] = i;
					cout <<"matrix["<<currentNode<<"]["<<i<<"]"<<matrix[currentNode][i] << "\n";
					//cout << "col. connectableNodes[" << conNodeToWrite << "]:" << connectableNodes[conNodeToWrite] << " \n";
			}
			
			cout << "returning connectable nodes array\n";
			//return connectableNodes;
		}
	
		
		
		// findMinSpanTree
		// find the minimum spanning tree for inputted matrix using Prims algorithm
		/*
			input: matrix (int [10][10]), matrix repreentation of graph to scan
			output:
		*/
		void findMinSpanTree(int matrix[10][10])
		{
			
			cout << "find min spanning tree";
			
			//zero out the min spanning tree
			for(int i = 0; i < N; i ++)
			{
				for(int j = 0; j < N; j ++)
				{
					minSpanningTree[i][j] = 0;
				}
			}
			
			// print the matrix
			printMatrix(matrix);
		   	
			currentNode = rand() % N;
			currentNode = 3;
			
		   	cout << "currentNode: " << currentNode << "\n ";
		   	
		   	nodesVisited = 0;
			cout << "nodesVisited:" << nodesVisited << "\n";
		   	
		   	// run loop while there are unvisited nodes
		   	while(nodesVisited < N)
		   	{
			   	cout << "currentNode: " << currentNode << "\n ";
 				
				// find all edges that are of distance 1 from the current node 
				distanceOneNodes( matrix );
				cout << "\n";
				
		   		// print connectable nodes array
		   		for( int i = 0; i < N; i++ )
		   		{
		   			cout << connectableNodes[i][0] << " ,";	
				}
				for( int i = 0; i < N; i++ )
		   		{
		   			cout << connectableNodes[i][1] << " ,";	
				}
				
				// determine the smallest-weighted edge in the distance-1 nodes array
				int smallestEdge[3] = { -1 };
				for(int i = 0; i < N; i++)
				{
					cout << "connectable node: " << connectableNodes[i][0] << "\tsmallest edge: " << smallestEdge[0] << "\n";
					if(smallestEdge[0] == -1 && minSpanningTree[currentNode][i] == -1)
					{
						cout << "\nfirst iteration is inserting first value into smallest edge\n";
						smallestEdge[0] = connectableNodes[i][0];
						smallestEdge[1] = connectableNodes[i][1];
						smallestEdge[2] = connectableNodes[i][2];
					} 
					else if( (connectableNodes[i][0] < smallestEdge[0]) && (connectableNodes[i][0] != -1) && (minSpanningTree[currentNode][i] == -1)|| (smallestEdge[0] == -1 ) )
					{
						cout << "updating the smallest edge\n";
						smallestEdge[0] = connectableNodes[i][0];
						smallestEdge[1] = connectableNodes[i][1];
						smallestEdge[2] = connectableNodes[i][2];
					}
					
					
				}
				
				// 
				cout << "\nweight: " << smallestEdge[0] << "\t current node: " << smallestEdge[1] << "\t target node: " << smallestEdge[2] << "\n";
				
				nextNode = smallestEdge[2];
				
				// build link in spanning tree between current node and next node if 
		   		visitedNodes[currentNode] = true;
		   		minSpanningTree[currentNode][nextNode] = 1;
		   		printMatrix(minSpanningTree);
		   		//break;
				  		
				// go to and check the next node
				currentNode = smallestEdge[2];
				
				nodesVisited ++;
		   		   	
		   	}
		   	
			cout << "we found it!\n";
		}
};

#endif