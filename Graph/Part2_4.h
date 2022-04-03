//created by Nicholas


#ifndef PART24_H
#define PART24_H

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#include "PriorityQueue.h"


class Part24
{
	protected:
		int N = 10;
		int path[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		int visited[10];
		int matrix[10][10] = {{-1, 3, -1, 9, -1, -1, -1, -1, -1, -1},
							{-1, -1, 6, -1, -1, -1, -1, -1, -1, -1},
							{1, -1, -1, 6, -1, -1, -1, -1, 14, -1},
							{-1, -1, -1, -1, 4, 3, -1, -1, -1, -1},
							{-1, -1, 6, -1, -1, -1, 7, 3, -1, -1},
							{-1, -1, -1, -1, -1, -1, 7, -1, -1, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1, -1, 3},
							{-1, -1, -1, -1, -1, -1, -1, -1, 4, -1},
							{-1, -1, -1, -1, -1, -1, -1, -1, -1, 6},
							{-1, -1, -1, -1, -1, 8, -1, -1, -1, -1}};
	public:
		Part24();
		~Part24();
		
		//notVisited
		//determine if a node has been visited or not
		/*
			input: node to analyze (int)
			return: true if node has not been visited
		*/
		bool notVisited(int node)
		{
			if(visited[node] == 1)
				return false;
				
			return true;
		}
		
		
		//toTestshortIsEmpty
		//determine in the "to test short" array is empty
		/*
			input: array to test 
			output: true if array is empty (zeros)
		*/
		bool toTestShortIsEmpty(int matrix[10])
		{
			for(int i = 0; i < 10; i++)
			{
				if(matrix[i] != 0)
				return false;
			}
			
			return true;
		}
		
		//PrintMatrix
		//print the matrix in... matrix form
		void PrintMatrix()
		{
			cout << "printing matrix:\n"; 
			//rows
			for(int i = 0; i < N; i++)
			{
				//columns
				for(int j = 0; j < N; j++)
				{
					int value = matrix[i][j]; 
					
					/*normalize spacing*/
					if(value < 0 || value > 9)
						cout << " [" << value << "] ";
					else 
						cout << " [ " << value << "] ";
					
				}
				cout << "\n";
			}
			cout << "matrix printed\n";		
		}
		
		
		//printPath
		//print the path
		/*
		*/
		void printPath()
		{
		}
		
		
		//smallestVal
		//determine the smallest length in array
		/*
			input: array 
			output: int of smallest term
		*/
		int smallestVal(int * array)
		{
		 int shortest = array[0];
			
			for(int i = 0; array[i] != 0; i ++)
				if(min(matrix[shortest], matrix[i]) != matrix[shortest])
					shortest = array[i];
				                  
			return shortest;
		}
		
		
		//shortestPath
		/*
			the idea, which you can see I have not been able to figure-out how to make work, was to perform a depth-1 search from the start node, then add all the edges to an array.  
			The shortest edge would then be followed, and a depth-1 search would be performed from it.  
			This would continue until either the target node is found or there are no more unsearched edges to scan.  
			Then, the "source node", or the origin would be set to one of the other nodes connected to the original head.  
			The process would repeat similarly from this node.
		*/
		/*
			input: node to find (int)
			output: 1, if success.  
		*/
		int shortestPath(int finalNode)
		{
			cout << "\n\nstarting shortestPath\n";
			
			PriorityQueue *pq = new PriorityQueue();
			
			int sourceNode = 0;
			
			while(true)
			{
				
				//matrix of outgoing nodes to determine which is shortest
				int toTestShort[10];
				
				//if we have found the final node
				if(sourceNode == finalNode)
				{
					cout << "success, path found.";
					printPath();
					return 1;
				}	
				
				//find all outgoing edges from the current node
				for(int i = 0; i < N; i++)
				{
					if(matrix[sourceNode][i] > 0 && notVisited(i))
					{
						//if we have found the final node
						if(i == finalNode)
						{
							cout << "success, path found.";
							printPath();
							return 1;
						}
						cout << " "<<i<<"\n";
						toTestShort[i] = 1;
						pq->Insert(i);
						
					}
					else
						cout << "!"<<i<<"\n";
						
					if(i == N && toTestShortIsEmpty(toTestShort))
					{
						sourceNode = pq->ExtractMin();
						break;
					}
				}
				
				// print testshort matrix
				for(int i = 0; i < 10; i ++)
					cout << toTestShort[i] <<" ";
				
				
				sourceNode = smallestVal(toTestShort); 
				cout << "next node: " << sourceNode;
				//break;
			}	
					
			cout << "\nshortest path ended\n";	
			
			return 1;
		}
};

#endif