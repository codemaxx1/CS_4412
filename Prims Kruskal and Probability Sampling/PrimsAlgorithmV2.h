// created by Nicholas Garrett
// 

#ifndef PRIMSALGORITHMV2_H
#define PRIMSALGORITHMV2_H


#include <iostream>
#include <fstream>
#include <string>
#include <String.h>
#include <stdio.h>
#include <stdlib.h>

#include "logging.h"

#define N 10

using namespace std;
class PrimsAlgorithmV2
{
	private:
		
		// build minimum spanning tree and initialize it with zeros
	   	int minSpanningTree[N][N] = {0};
	   	
	   	// globally accessable matrix.  This is so that complex returns from functions can be removed and the matrix can be read directly
	   	int matrix[N][N];	   	
	   	
	   	
		// array of points that can be reached through a reach-one search.
		/*
			[0] -> the weight
			[1] -> the current node							__\\
			[2] -> the "next" node to be connected to         // these two represent an edge
		*/
		int reach1Points[N][3];
		
		
		// this variable stores what the current node being analyzed from is. This is by default set to vertex 0, though it is reset to a randomly generated node later in the code
		int currentNode = 0;
		
		
		// array to store which nodes have been inserted into the min spanning tree
		int insertedNodes[N];
		
		
	public:
		PrimsAlgorithmV2();
		~PrimsAlgorithmV2();
		
		
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


		
		// updateReach1Points
		// update the reach1Points matrix with the new points/nodes and edges that can be reached with a single step
		/*
		*/
		void updateReach1Points( )
		{
			
			// reset the reach1Points array to 0 for each point
			//cout << "reseting reach1points array\n";
			for(int i = 0; i < N; i ++)
			{
				for(int j = 0; j < 3; j ++)
				{
					reach1Points[i][j] = 0;
					//cout << reach1Points[i][j] << " ";
				}
				//cout << "\n";
			}
			//cout << "reach 1 array reset\n";
			
			
			// variable to store the node being set in the array of reach 1 nodes
			int writePosition = 0;
			
			
			// begin at the starting point and find all connectable nodes by searching the represented edges in the current node's row and column
			for( int i = 0; i < N; i ++)
			{
				
				// if there is a represented edge between the iterated column and currentNode's row.  This will only occur if there is an edge between the current node and whatever node is being iterated through
				if( matrix[i][currentNode] != 0)
				{
					//cout << "edge: " << currentNode << " -> " << i << "\n";
					reach1Points[writePosition][ 0 ] = matrix[i][currentNode];
					reach1Points[writePosition][ 1 ] = currentNode;
					reach1Points[writePosition][ 2 ] = i; 
					
					// iterate the write position variable
					writePosition ++;
				}
				
			
			
				// if there is a represented edge between the iterated row and currentNode's column.  This will only occur if there is an edge between the current node and whatever node is being iterated through
				if( matrix[currentNode][i] != 0)
				{
					//cout << "edge: " << currentNode << " -> " << i << "\n";
					reach1Points[writePosition][ 0 ] = matrix[currentNode][i];
					reach1Points[writePosition][ 1 ] = currentNode;
					reach1Points[writePosition][ 2 ] = i; 
					
					// iterate the write position variable
					writePosition ++;
				}
			}
			
			
			// print the "reach1Points" matrix
			/*
			for(int i = 0; i < N; i ++)
			{
				for( int j = 0; j < 3; j ++)
				{
					cout << reach1Points[i][j] << " ";
				}
				cout << "\n";
			}
			*/
			
			//cout << "array of reach-1 accessable nodes has been updated\n";
			
		}
		
		
		
		// findMinSpanTree
		// find the minimum spanning tree for inputted matrix using Prims algorithm
		/*
			input: matrix (int [10][10]), matrix repreentation of graph to scan
			output:
		*/
		void findMinSpanTree(int inputtedMatrix[10][10])
		{
			//cout << "beginning assembly of minimum spanning tree by Prims algorithm: \n";
			
			
			// initialize logging
			logging *logging;
			
		
			// copy the inputted matrix named "inputtedMatrix" to the globally set matrix "matrix"
			for(int i = 0; i < N; i ++)
			{
				for( int j = 0; j < N; j ++)
				{
					matrix[i][j] = inputtedMatrix[i][j];
				}
			}
			//printMatrix(matrix);
		
		
			// zero out the minSpanningTree
			for(int i = 0; i < N; i++)
			{
				for( int j = 0; j < N; j ++)
				{
					minSpanningTree[i][j] = 0;
					//cout << minSpanningTree[i][j] << " ";
				 } 
			}
		
		
			// zero out the array of nodes in the min spanning tree
			//cout << "resetting array of inserted nodes in the tree\n";
			for (int i = 0; i < N; i ++)
			{
				insertedNodes[i] = -1;
				
				//cout << insertedNodes[i] << " ";
			}
			//cout << "array of nodes in min. spanning tree reset\n";
			
			
			
			// find the first vertex of the graph to start from
			int firstVertex = rand() % N;
			insertedNodes[firstVertex] = 1;
						
			
			
			// variable to store a the number of vertices (nodes) that have been inserted into the tree
			int insertedVertices = 0;
			
			
			
			// this variable stores what the current node being analyzed from is. This is by default set to the randomly-determined "first vertex"
			currentNode = firstVertex;
		
			
			
			// loop to expand the tree.  This will run until all nodes (vertices) are in the tree (array [matrix])
			while( insertedVertices < N)
			{
				
				// update the array of nodes that can be accessed from the current node
				updateReach1Points();
				
				// print the current node
				//cout << "Current Node: " << currentNode << "\n";
				
				
				// variable to store the smallest edge, which will be written into the min. spanning tree
				/*
					[0] -> weight
					[1] -> current node		__\\
					[2] -> next node		  //   these two represent an edge
				*/
				int smallestEdge[3] = {-1,-1,-1};

				/* 
					iterate through all the nodes in the reach 1 points array.  
					For the smallest one that connects to a node not in the min spanning tree, add it into the min. spanning tree
				*/
				for( int i = 0; i < N; i ++)
				{
					
					// end the loop if the checked value is 0.  This will only occur if that node in the array has not been overwritten, so no node exists at this point.
					if(reach1Points[i][0] == 0)break;  
					
				
					// TODO: if there are no edges that exist not already in the matrix, then... iterate thorugh the nodes in the matrix, building an array of edges to nodes not in it yet, and then follow the smallest one.

					
					// for the first iteration ( or the first edge that reaches a node not already in the min spanning tree ) add it to the tree without comparing
					//cout << "insertedNodes[reach1Points["<<i<<"][2]] == " << "insertedNodes[" << reach1Points[i][2] << "]: " << insertedNodes[reach1Points[i][2]] << "\n";
					if ( smallestEdge[0] == -1 && insertedNodes[reach1Points[i][2]] == -1 )
					{	
						smallestEdge[0] = reach1Points[i][0];
						smallestEdge[1] = reach1Points[i][1];
						smallestEdge[2] = reach1Points[i][2];
						
						//cout << "smallest edge first inserted: " << smallestEdge[1] << " -> " << smallestEdge[2] << " of len. " << smallestEdge[0] << "\n";
					}
					
					//  insert the smallest length edge to a node not in the min. spanning tree (represented by the insertedNodes array)
					else if( smallestEdge[0] != -1 && reach1Points[i][0] < smallestEdge[0]  && insertedNodes[reach1Points[i][2]] == -1)
					{
						smallestEdge[0] = reach1Points[i][0];
						smallestEdge[1] = reach1Points[i][1];
						smallestEdge[2] = reach1Points[i][2];
						
						//cout << "smallest edge smaller inserted: " << smallestEdge[1] << " -> " << smallestEdge[2] << smallestEdge[0] << "\n";
					}					
					
				}
			
			
				// insert the smallest edge node into the min spanning tree and add that node to the insertedNodes array
				minSpanningTree[smallestEdge[1]][smallestEdge[2]] = smallestEdge[0];
				minSpanningTree[smallestEdge[2]][smallestEdge[1]] = smallestEdge[0];
				//printMatrix(minSpanningTree);
				
				insertedNodes[currentNode] = 1;
				
				// print the insertedNodes array
				/*
				for(int i = 0; i < N; i ++)
				{
					cout << insertedNodes[i] << " ";
				 } 
				 */
				 
				// set the "current node" to the node connected-to by it with the smallest edge
				currentNode = smallestEdge[2];
				//cout << "new current node: " << currentNode << "\n";
			
			
				insertedVertices ++;
				// break the loop on a single iteration
				//cout << "for tesing, this loop is broken on a single iteration.\n";
				//break;
			}
			

			cout << "\nMinimum spanning tree found by Prims Algorithm: \n";
			
			
			// print out the min spanning tree in a (somewhat) nice manner
			for(int i = 0; i < N+1; i++)
			{
				if(i != 0)	cout << i << " +";
				else cout << "   ";
				for(int k = 0; k < i; k ++)
				{
					cout << "--";
				}
				if(i == 0)cout << "  ";
				for(int j = i; j < N+1; j++)
				{
					
					if( i == 0 && j > 0) 	cout << j << " ";
					
					
					if( i > 0)				cout << minSpanningTree[i-1][j-1] << " ";
				}
				cout << "\n";
				if( i == 0)
				{
					cout << "     ";
					
					for(int l = 0; l < N; l++)
					cout << "+ ";
					
					cout << "\n";
				}
				
			}
				
		}
			


};

#endif